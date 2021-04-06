cmake_minimum_required(VERSION 3.10)
project(lookup_test)

# Pick the C++ standard to compile with.
# Abseil currently supports C++11, C++14, and C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Release")

set(BENCHMARK_ENABLE_TESTING NO)

add_subdirectory(3rdparty/benchmark)
add_subdirectory(3rdparty/abseil-cpp)

add_executable(lookup lookup.cpp)
target_link_libraries(lookup 
	absl::flat_hash_map
	absl::str_format
	benchmark::benchmark
)

add_executable(lower_bound lower_bound.cpp)
target_link_libraries(lower_bound
	absl::flat_hash_map
	# absl::str_format
	benchmark::benchmark
)
