FROM ros:rolling

RUN apt-get upgrade \
    && apt-get update \
    && apt-get install -y \
        ros-$ROS_DISTRO-rclcpp \
        ros-$ROS_DISTRO-std-msgs \
        ros-$ROS_DISTRO-std-msgs-dbgsym \
        ros-$ROS_DISTRO-rmw-dbgsym \
        ros-$ROS_DISTRO-rmw-implementation-dbgsym \
        ros-$ROS_DISTRO-rmw-fastrtps-cpp \
        ros-$ROS_DISTRO-rmw-fastrtps-cpp-dbgsym \
        ros-$ROS_DISTRO-rmw-fastrtps-shared-cpp-dbgsym \
    && apt-get clean
