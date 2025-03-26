# ROS benchmarks

This repository contains some benchmarks to compare ROS 1 and 2.

## Serialization

TODO Equalize MHz.

### Noetic

```
Run on (12 X 4109.57 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 256 KiB (x6)
  L3 Unified 12288 KiB (x1)
Load Average: 0.56, 0.59, 0.88
---------------------------------------------------------------------------------------------------------------------------
Benchmark                                                                 Time             CPU   Iterations UserCounters...
---------------------------------------------------------------------------------------------------------------------------
BM_benchmarkHeaderAllocSerialization/std_msgs_header                   34.5 ns         34.5 ns     20664653 bytes_per_second=581.012M/s
BM_benchmarkHeaderAllocSerialization/std_msgs_bool                     31.1 ns         31.1 ns     22928647 bytes_per_second=30.6502M/s
BM_benchmarkHeaderAllocSerialization/geometry_msgs_pose_array           876 ns          875 ns       818353 bytes_per_second=11.9428G/s
```

### Galactic

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
BM_serialization/std_msgs_header                        1253 ns         1253 ns       577800 bytes_per_second=16.7503M/s
BM_serialization/std_msgs_bool                          1298 ns         1298 ns       542943 bytes_per_second=5.87745M/s
BM_serialization/geometry_msgs_pose_array               7961 ns         7961 ns        87291 bytes_per_second=1.31355G/s
```
