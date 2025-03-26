#include <benchmark/benchmark.h>

#if BENCH_ROS_VERSION == 1
#include <geometry_msgs/PoseArray.h>
#include <ros/message_deserializer.h>
#include <ros/ros.h>
#include <ros/serialization.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Header.h>
#define ROS_MESSAGE(package, name) package::name
#elif BENCH_ROS_VERSION == 2
#include <geometry_msgs/msg/pose_array.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/serialization.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/header.hpp>
#define ROS_MESSAGE(package, name) package::msg::name
#endif

ROS_MESSAGE(std_msgs, Header) createStdMsgsHeader()
{
    ROS_MESSAGE(std_msgs, Header) message;
    message.frame_id = "world";
    return message;
}

ROS_MESSAGE(std_msgs, Bool) createStdMsgsBool()
{
    ROS_MESSAGE(std_msgs, Bool) message;
    message.data = true;
    return message;
}

ROS_MESSAGE(geometry_msgs, PoseArray) createGeometryMsgsPoseArray()
{
    ROS_MESSAGE(geometry_msgs, PoseArray) poseArray;
    poseArray.header.frame_id = "world";
    ROS_MESSAGE(geometry_msgs, Pose) pose;
    pose.orientation.w = 1.;
    pose.position.x = 42.;
    pose.position.y = -123.;
    poseArray.poses.resize(200, pose);
    return poseArray;
}

template <class M>
size_t getMessageLength(const M &message)
{
#if BENCH_ROS_VERSION == 1
    return ros::serialization::serializationLength(message);
#elif BENCH_ROS_VERSION == 2
    rclcpp::Serialization<M> serialization;
    rclcpp::SerializedMessage serializedMessage;
    serialization.serialize_message(&message, &serializedMessage);
    return serializedMessage.size();
#endif
}

template <class M>
void BM_serialization(benchmark::State &state, const M &message)
{
#if BENCH_ROS_VERSION == 1
    // Warm-up
    for (int i = 0; i < 10; ++i)
    {
        ros::SerializedMessage result = ros::serialization::serializeMessage(message);
        benchmark::DoNotOptimize(result);
    }

    for (auto _ : state)
    {
        ros::SerializedMessage result = ros::serialization::serializeMessage(message);
        benchmark::DoNotOptimize(result);
    }
#elif BENCH_ROS_VERSION == 2
    rclcpp::Serialization<M> serialization;
    // Warm-up
    for (int i = 0; i < 10; ++i)
    {
        rclcpp::SerializedMessage result;
        serialization.serialize_message(&message, &result);
        benchmark::DoNotOptimize(result);
    }
    for (auto _ : state)
    {
        rclcpp::SerializedMessage result;
        serialization.serialize_message(&message, &result);
        benchmark::DoNotOptimize(result);
    }
#endif
    state.SetBytesProcessed(static_cast<int64_t>(getMessageLength(message) * state.iterations()));
}
BENCHMARK_CAPTURE(BM_serialization, std_msgs_header, createStdMsgsHeader());
BENCHMARK_CAPTURE(BM_serialization, std_msgs_bool, createStdMsgsBool());
BENCHMARK_CAPTURE(BM_serialization, geometry_msgs_pose_array, createGeometryMsgsPoseArray());

template <class M>
void BM_preAllocSerialization(benchmark::State &state, const M &message)
{
#if BENCH_ROS_VERSION == 1
    // Pre-alloc the buffer.
    ros::SerializedMessage result;
    uint32_t len = ros::serialization::serializationLength(message);
    result.num_bytes = len + 4;
    result.buf.reset(new uint8_t[result.num_bytes]);

    // Warm-up.
    for (int i = 0; i < 10; ++i)
    {
        ros::serialization::OStream s(result.buf.get(), static_cast<uint32_t>(result.num_bytes));
        serialize(s, static_cast<uint32_t>(result.num_bytes) - 4);
        result.message_start = s.getData();
        serialize(s, message);
    }

    for (auto _ : state)
    {
        ros::serialization::OStream s(result.buf.get(), static_cast<uint32_t>(result.num_bytes));
        serialize(s, static_cast<uint32_t>(result.num_bytes) - 4);
        result.message_start = s.getData();
        serialize(s, message);
        benchmark::DoNotOptimize(result);
    }

#elif BENCH_ROS_VERSION == 2
    rclcpp::Serialization<M> serialization;
    rclcpp::SerializedMessage result;
    // Warm-up & pre-alloc result.
    for (int i = 0; i < 10; ++i)
    {
        serialization.serialize_message(&message, &result);
        benchmark::DoNotOptimize(result);
    }

    for (auto _ : state)
    {
        serialization.serialize_message(&message, &result);
        benchmark::DoNotOptimize(result);
    }
#endif
    state.SetBytesProcessed(static_cast<int64_t>(getMessageLength(message) * state.iterations()));
}

BENCHMARK_CAPTURE(BM_preAllocSerialization, std_msgs_header, createStdMsgsHeader());
BENCHMARK_CAPTURE(BM_preAllocSerialization, std_msgs_bool, createStdMsgsBool());
BENCHMARK_CAPTURE(BM_preAllocSerialization, geometry_msgs_pose_array, createGeometryMsgsPoseArray());

int main(int argc, char **argv)
{
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv))
        return 1;
    ::benchmark::RunSpecifiedBenchmarks();
    return 0;
}
