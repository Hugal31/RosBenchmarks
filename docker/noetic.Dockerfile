FROM ros:noetic

RUN apt-get upgrade \
    && apt-get update \
    && apt-get install -y \
        ros-noetic-roscpp \
        ros-noetic-std-msgs \
        libbenchmark-dev \
    && apt-get clean
