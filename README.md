# ROS benchmarks

This repository contains some benchmarks to compare ROS 1 and 2.

## Serialization

Simple test of serialization using multiple messages.

### Noetic

```
Run on (12 X 4213.38 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 256 KiB (x6)
  L3 Unified 12288 KiB (x1)
Load Average: 0.56, 0.59, 0.88
---------------------------------------------------------------------------------------------------------------------------
Benchmark                                                                 Time             CPU   Iterations UserCounters...
---------------------------------------------------------------------------------------------------------------------------
BM_serialization/std_msgs_header                        35.4 ns         35.4 ns     20223211 bytes_per_second=565.588M/s
BM_serialization/std_msgs_bool                          31.8 ns         31.8 ns     20964098 bytes_per_second=30.019M/s
BM_serialization/geometry_msgs_pose_array                883 ns          883 ns       806462 bytes_per_second=11.8422G/s
```

### Galactic

Using `rmw_fastrtps_cpp`.

```
Run on (12 X 4500 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 256 KiB (x6)
  L3 Unified 12288 KiB (x1)
Load Average: 0.36, 0.65, 0.94
------------------------------------------------------------------------------------------------------------
Benchmark                                                  Time             CPU   Iterations UserCounters...
------------------------------------------------------------------------------------------------------------
BM_serialization/std_msgs_header                        1166 ns         1166 ns       595924 bytes_per_second=17.9911M/s
BM_serialization/std_msgs_bool                          1155 ns         1155 ns       606509 bytes_per_second=6.60702M/s
BM_serialization/geometry_msgs_pose_array               8226 ns         8225 ns        84909 bytes_per_second=1.27132G/s
```
