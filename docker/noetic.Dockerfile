FROM ros:noetic

RUN apt-get upgrade \
    && apt-get update \
    && apt-get install -y \
        git \
        ros-noetic-roscpp \
        ros-noetic-std-msgs \
    && apt-get clean
