ARG ROS_DISTRO=rolling
FROM ros:$ROS_DISTRO

RUN apt-get upgrade \
    && apt-get update \
    && RTI_NC_LICENSE_ACCEPTED=yes apt-get install -y \
        ros-$ROS_DISTRO-rclcpp \
        ros-$ROS_DISTRO-std-msgs \
        ros-$ROS_DISTRO-std-msgs-dbgsym \
        ros-$ROS_DISTRO-rmw-dbgsym \
        ros-$ROS_DISTRO-rmw-implementation-dbgsym \
        ros-$ROS_DISTRO-rmw-connextdds-dbgsym \
        ros-$ROS_DISTRO-rmw-connextdds-common-dbgsym \
        ros-$ROS_DISTRO-rmw-cyclonedds-cpp-dbgsym \
        ros-$ROS_DISTRO-rmw-gurumdds-cpp-dbgsym \
        ros-$ROS_DISTRO-rmw-fastrtps-cpp-dbgsym \
        ros-$ROS_DISTRO-rmw-fastrtps-shared-cpp-dbgsym \
        ros-$ROS_DISTRO-rmw-zenoh-cpp-dbgsym \
    && apt-get clean
