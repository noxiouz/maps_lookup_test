# Lookup IPv4 like struct in different maps

## Build and run

```
mkdir -p build && cd build
cmake ../ && make -j4 && ./lookup
```

## Result from VSL on Windows

```
2020-11-20T22:02:03+00:00
Running ./lookup
Run on (16 X 3600.12 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 512 KiB (x8)
  L3 Unified 16384 KiB (x1)
Load Average: 1.86, 0.74, 0.29
------------------------------------------------------------------------------------------------------------------------------------
Benchmark                                                                          Time             CPU   Iterations UserCounters...
------------------------------------------------------------------------------------------------------------------------------------
MapAddressLookup<std::map<Address, Value>>/1024                                 38.9 ns         38.9 ns     17522288 actual_size=1024
MapAddressLookup<std::map<Address, Value>>/2048                                 39.9 ns         39.9 ns     17173424 actual_size=2.048k
MapAddressLookup<std::map<Address, Value>>/4096                                 44.4 ns         44.4 ns     15278531 actual_size=4.096k
MapAddressLookup<std::map<Address, Value>>/8192                                 45.7 ns         45.7 ns     14813609 actual_size=8.192k
MapAddressLookup<std::map<Address, Value>>/16384                                50.5 ns         50.5 ns     13797419 actual_size=16.384k
MapAddressLookup<std::map<Address, Value>>/32768                                53.5 ns         53.5 ns     12548898 actual_size=32.767k
MapAddressLookup<std::map<Address, Value>>/65536                                58.0 ns         58.0 ns     11155060 actual_size=65.535k
MapStringLookup<std::map<std::string, Value>>/1024                               196 ns          196 ns      3493154 actual_size=1024
MapStringLookup<std::map<std::string, Value>>/2048                               209 ns          209 ns      3305715 actual_size=2.048k
MapStringLookup<std::map<std::string, Value>>/4096                               233 ns          233 ns      3000497 actual_size=4.096k
MapStringLookup<std::map<std::string, Value>>/8192                               243 ns          243 ns      2815012 actual_size=8.192k
MapStringLookup<std::map<std::string, Value>>/16384                              249 ns          249 ns      2795988 actual_size=16.384k
MapStringLookup<std::map<std::string, Value>>/32768                              277 ns          277 ns      2506512 actual_size=32.767k
MapStringLookup<std::map<std::string, Value>>/65536                              302 ns          302 ns      2322309 actual_size=65.535k
MapAddressLookup<std::unordered_map<Address, Value, Address_hash>>/1024         32.7 ns         32.7 ns     21180748 actual_size=1024
MapAddressLookup<std::unordered_map<Address, Value, Address_hash>>/2048         42.1 ns         42.1 ns     16491420 actual_size=2.048k
MapAddressLookup<std::unordered_map<Address, Value, Address_hash>>/4096         31.4 ns         31.4 ns     22078196 actual_size=4.096k
MapAddressLookup<std::unordered_map<Address, Value, Address_hash>>/8192         30.1 ns         30.1 ns     23199857 actual_size=8.192k
MapAddressLookup<std::unordered_map<Address, Value, Address_hash>>/16384        29.9 ns         29.9 ns     23194844 actual_size=16.384k
MapAddressLookup<std::unordered_map<Address, Value, Address_hash>>/32768        28.8 ns         28.8 ns     24370234 actual_size=32.767k
MapAddressLookup<std::unordered_map<Address, Value, Address_hash>>/65536        37.6 ns         37.6 ns     18688139 actual_size=65.535k
MapStringLookup<std::unordered_map<std::string, Value>>/1024                    69.9 ns         69.9 ns     10011138 actual_size=1024
MapStringLookup<std::unordered_map<std::string, Value>>/2048                    74.3 ns         74.3 ns      9398365 actual_size=2.048k
MapStringLookup<std::unordered_map<std::string, Value>>/4096                    69.1 ns         69.1 ns     10541731 actual_size=4.096k
MapStringLookup<std::unordered_map<std::string, Value>>/8192                    68.9 ns         68.9 ns      9998903 actual_size=8.192k
MapStringLookup<std::unordered_map<std::string, Value>>/16384                   55.9 ns         55.9 ns     12610004 actual_size=16.384k
MapStringLookup<std::unordered_map<std::string, Value>>/32768                   75.6 ns         75.6 ns      9256959 actual_size=32.767k
MapStringLookup<std::unordered_map<std::string, Value>>/65536                   55.3 ns         55.3 ns     12727919 actual_size=65.535k
MapAddressLookup<absl::btree_map<Address, Value>>/1024                          76.8 ns         76.8 ns      8900329 actual_size=1024
MapAddressLookup<absl::btree_map<Address, Value>>/2048                          89.4 ns         89.4 ns      7878857 actual_size=2.048k
MapAddressLookup<absl::btree_map<Address, Value>>/4096                          86.0 ns         86.1 ns      7888964 actual_size=4.096k
MapAddressLookup<absl::btree_map<Address, Value>>/8192                          93.6 ns         93.6 ns      7309818 actual_size=8.192k
MapAddressLookup<absl::btree_map<Address, Value>>/16384                          107 ns          107 ns      6482245 actual_size=16.384k
MapAddressLookup<absl::btree_map<Address, Value>>/32768                          111 ns          111 ns      6059009 actual_size=32.767k
MapAddressLookup<absl::btree_map<Address, Value>>/65536                          114 ns          114 ns      5925876 actual_size=65.535k
MapStringLookup<absl::btree_map<std::string, Value>>/1024                        252 ns          252 ns      2767145 actual_size=1024
MapStringLookup<absl::btree_map<std::string, Value>>/2048                        245 ns          245 ns      2841480 actual_size=2.048k
MapStringLookup<absl::btree_map<std::string, Value>>/4096                        266 ns          266 ns      2626603 actual_size=4.096k
MapStringLookup<absl::btree_map<std::string, Value>>/8192                        292 ns          292 ns      2376315 actual_size=8.192k
MapStringLookup<absl::btree_map<std::string, Value>>/16384                       305 ns          305 ns      2313194 actual_size=16.384k
MapStringLookup<absl::btree_map<std::string, Value>>/32768                       338 ns          338 ns      2050983 actual_size=32.767k
MapStringLookup<absl::btree_map<std::string, Value>>/65536                       346 ns          346 ns      2005163 actual_size=65.535k
MapAddressLookup<absl::flat_hash_map<Address, Value, Address_hash>>/1024        13.3 ns         13.3 ns     51472984 actual_size=1024
MapAddressLookup<absl::flat_hash_map<Address, Value, Address_hash>>/2048        13.2 ns         13.2 ns     53126522 actual_size=2.048k
MapAddressLookup<absl::flat_hash_map<Address, Value, Address_hash>>/4096        13.2 ns         13.2 ns     53214940 actual_size=4.096k
MapAddressLookup<absl::flat_hash_map<Address, Value, Address_hash>>/8192        13.2 ns         13.2 ns     53338974 actual_size=8.192k
MapAddressLookup<absl::flat_hash_map<Address, Value, Address_hash>>/16384       13.2 ns         13.2 ns     52790389 actual_size=16.384k
MapAddressLookup<absl::flat_hash_map<Address, Value, Address_hash>>/32768       13.1 ns         13.1 ns     54018655 actual_size=32.767k
MapAddressLookup<absl::flat_hash_map<Address, Value, Address_hash>>/65536       13.1 ns         13.1 ns     53226013 actual_size=65.535k
MapStringLookup<absl::flat_hash_map<std::string, Value>>/1024                    349 ns          349 ns      1887628 actual_size=1024
MapStringLookup<absl::flat_hash_map<std::string, Value>>/2048                    295 ns          295 ns      2044124 actual_size=2.048k
MapStringLookup<absl::flat_hash_map<std::string, Value>>/4096                    324 ns          324 ns      2664376 actual_size=4.096k
MapStringLookup<absl::flat_hash_map<std::string, Value>>/8192                    320 ns          320 ns      2796160 actual_size=8.192k
MapStringLookup<absl::flat_hash_map<std::string, Value>>/16384                   345 ns          345 ns      2314284 actual_size=16.384k
MapStringLookup<absl::flat_hash_map<std::string, Value>>/32768                   363 ns          363 ns      2020608 actual_size=32.767k
MapStringLookup<absl::flat_hash_map<std::string, Value>>/65536                   353 ns          353 ns      2043570 actual_size=65.535k
```
