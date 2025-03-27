FROM ros:jazzy

RUN apt-get upgrade \
    && apt-get update \
    && apt-get install -y \
        ros-jazzy-rclcpp \
        ros-jazzy-std-msgs \
        ros-jazzy-std-msgs-dbgsym \
        ros-jazzy-rmw-dbgsym \
        ros-jazzy-rmw-implementation-dbgsym \
        ros-jazzy-rmw-fastrtps-cpp \
        ros-jazzy-rmw-fastrtps-cpp-dbgsym \
        ros-jazzy-rmw-fastrtps-shared-cpp-dbgsym \
    && apt-get clean
