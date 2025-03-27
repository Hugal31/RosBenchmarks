# ROS benchmarks

This repository contains some benchmarks to compare ROS 1 and 2.

## Serialization

Simple test of serialization using multiple messages.

### Noetic

```
Running /tmp/RosBenchmarks/cmake-build-release-noetic-docker/benchmarks
Run on (12 X 3804.02 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 256 KiB (x6)
  L3 Unified 12288 KiB (x1)
Load Average: 4.67, 3.19, 1.95
------------------------------------------------------------------------------------------------------------
Benchmark                                                  Time             CPU   Iterations UserCounters...
------------------------------------------------------------------------------------------------------------
BM_serialization/std_msgs_header                        41.1 ns         41.1 ns     12926923 bytes_per_second=486.814Mi/s
BM_serialization/std_msgs_bool                          34.5 ns         34.5 ns     19906493 bytes_per_second=27.6148Mi/s
BM_serialization/geometry_msgs_pose_array                943 ns          943 ns       727371 bytes_per_second=11.0872Gi/s
BM_deserialization/std_msgs_header                      9.84 ns         9.84 ns     73337815 bytes_per_second=1.98697Gi/s
BM_deserialization/std_msgs_bool                        1.12 ns         1.12 ns    656150880 bytes_per_second=850.838Mi/s
BM_deserialization/geometry_msgs_pose_array              977 ns          976 ns       846376 bytes_per_second=10.7067Gi/s
BM_preAllocSerialization/std_msgs_header                6.55 ns         6.55 ns     90181361 bytes_per_second=2.98576Gi/s
BM_preAllocSerialization/std_msgs_bool                  1.45 ns         1.45 ns    426181641 bytes_per_second=658.477Mi/s
BM_preAllocSerialization/geometry_msgs_pose_array        941 ns          941 ns       684112 bytes_per_second=11.1067Gi/s
```

### Rolling

Benchmarked the 2025/03/27 using:
- rclcpp 29.3.0
- rcl 10.0.2
- rmw 7.8.1
- rmw_implementation 3.0.4
- rmw_fastrtps_cpp 9.3.1

```
Run on (12 X 4053.22 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 256 KiB (x6)
  L3 Unified 12288 KiB (x1)
Load Average: 1.36, 2.42, 1.87
------------------------------------------------------------------------------------------------------------
Benchmark                                                  Time             CPU   Iterations UserCounters...
------------------------------------------------------------------------------------------------------------
BM_serialization/std_msgs_header                        1110 ns         1109 ns       674526 bytes_per_second=18.9143Mi/s
BM_serialization/std_msgs_bool                          1080 ns         1080 ns       639051 bytes_per_second=7.06441Mi/s
BM_serialization/geometry_msgs_pose_array              19956 ns        19954 ns        36460 bytes_per_second=536.615Mi/s
BM_deserialization/std_msgs_header                      1122 ns         1122 ns       604792 bytes_per_second=18.6966Mi/s
BM_deserialization/std_msgs_bool                        1108 ns         1108 ns       639641 bytes_per_second=6.88718Mi/s
BM_deserialization/geometry_msgs_pose_array            16997 ns        16976 ns        41015 bytes_per_second=630.747Mi/s
BM_preAllocSerialization/std_msgs_header                1012 ns         1010 ns       705317 bytes_per_second=20.7671Mi/s
BM_preAllocSerialization/std_msgs_bool                   978 ns          976 ns       730294 bytes_per_second=7.81327Mi/s
BM_preAllocSerialization/geometry_msgs_pose_array      18601 ns        18600 ns        37163 bytes_per_second=575.697Mi/s
```
