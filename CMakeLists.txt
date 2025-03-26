cmake_minimum_required(VERSION 3.16)
project(RosBenchmarks)

set(CMAKE_CXX_STANDARD 17)

find_package(benchmark REQUIRED)

add_executable(benchmarks src/serialization.cpp)
target_link_libraries(benchmarks PRIVATE benchmark::benchmark)

if ($ENV{ROS_VERSION} EQUAL 1)
    find_package(roscpp REQUIRED)
    find_package(geometry_msgs REQUIRED)
    find_package(std_msgs REQUIRED)
    target_include_directories(benchmarks SYSTEM PRIVATE
        ${roscpp_INCLUDE_DIRS}
        ${geometry_msgs_INCLUDE_DIRS}
        ${std_msgs_INCLUDE_DIRS})
    target_link_libraries(benchmarks PRIVATE
        ${geometry_msgs_LIBRARIES}
        ${roscpp_LIBRARIES}
        ${std_msgs_LIBRARIES})
elseif ($ENV{ROS_VERSION} EQUAL 2)
    find_package(rclcpp REQUIRED)
    find_package(geometry_msgs REQUIRED)
    find_package(std_msgs REQUIRED)
    target_link_libraries(benchmarks PRIVATE rclcpp::rclcpp geometry_msgs::geometry_msgs__rosidl_typesupport_cpp std_msgs::std_msgs__rosidl_typesupport_cpp)
else()
    message(FATAL_ERROR "Missing ROS_VERSION environment variable")
endif ()

target_compile_definitions(benchmarks PRIVATE BENCH_ROS_VERSION=$ENV{ROS_VERSION})
