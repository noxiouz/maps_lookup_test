#include <array>
#include <algorithm>
#include <string>
#include <random>
#include <map>
#include <unordered_map>

#include <benchmark/benchmark.h>
#include <absl/container/btree_map.h>
#include <absl/container/flat_hash_map.h>
#include <absl/strings/str_format.h>

using Address = std::pair<uint32_t, uint16_t>;
using Value = std::array<char, 16>;

struct Address_hash{
   std::size_t operator() (const Address& a) const {
       return std::hash<Address::first_type>()(a.first) ^ std::hash<Address::second_type>()(a.second);
   }
};


std::vector<Address> gen(size_t n) {
   std::vector<Address> v;
   v.reserve(n);
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<uint32_t> d(1, 1 << 31);
   for (size_t i = 0; i < n; ++i) {
       v.emplace_back(d(gen), 8080);  
   }
   return v;
}

template<typename M>
void MapAddressLookup(benchmark::State& state) {
  size_t n = (size_t)state.range(0);
  auto input = gen(n);
  M m;
  const auto& v = input; 
  std::for_each(v.begin(), v.end(), [&m](auto i) {
      m.emplace(i, Value{});
  });
  state.counters["actual_size"] = m.size();
  for (auto _ : state) {
      benchmark::DoNotOptimize(m.find(v[0]));
      benchmark::DoNotOptimize(m.find(v[1]));
      benchmark::DoNotOptimize(m.find(v[2]));
      benchmark::DoNotOptimize(m.find(v[n-1]));
      benchmark::DoNotOptimize(m.find(v[n-2]));
  }
}

template<typename M>
void MapStringLookup(benchmark::State& state) {
  size_t n = (size_t)state.range(0);
  auto input = gen(n);
  M m;
  std::vector<std::string> v;
  v.reserve(input.size());
  std::transform(input.begin(), input.end(), std::back_inserter(v), [&m](auto i) {
      auto [a, port] = i;
      auto addr = absl::StrFormat("%d.%d.%d.%d:%d", a & 0xFF, (a >> 8) & 0xFF, (a >> 16) & 0xFF, (a >> 24) & 0xFF, port);
      return addr;
  });
  std::for_each(v.begin(), v.end(), [&m](auto i) {
      m.emplace(i, Value{});
  });
  state.counters["actual_size"] = m.size();
  for (auto _ : state) {
      benchmark::DoNotOptimize(m.find(v[0]));
      benchmark::DoNotOptimize(m.find(v[1]));
      benchmark::DoNotOptimize(m.find(v[2]));
      benchmark::DoNotOptimize(m.find(v[n-1]));
      benchmark::DoNotOptimize(m.find(v[n-2]));
  }
}

constexpr auto down = 1 << 10;
constexpr auto up =  1 << 16;

BENCHMARK_TEMPLATE(MapAddressLookup, std::map<Address, Value>)->RangeMultiplier(2)->Range(down, up);
BENCHMARK_TEMPLATE(MapStringLookup, std::map<std::string, Value>)->RangeMultiplier(2)->Range(down, up);

BENCHMARK_TEMPLATE(MapAddressLookup, std::unordered_map<Address, Value, Address_hash>)->RangeMultiplier(2)->Range(down, up);
BENCHMARK_TEMPLATE(MapStringLookup, std::unordered_map<std::string, Value>)->RangeMultiplier(2)->Range(down, up);

BENCHMARK_TEMPLATE(MapAddressLookup, absl::btree_map<Address, Value>)->RangeMultiplier(2)->Range(down, up);
BENCHMARK_TEMPLATE(MapStringLookup, absl::btree_map<std::string, Value>)->RangeMultiplier(2)->Range(down, up);

BENCHMARK_TEMPLATE(MapAddressLookup, absl::flat_hash_map<Address, Value, Address_hash>)->RangeMultiplier(2)->Range(down, up);
BENCHMARK_TEMPLATE(MapStringLookup, absl::flat_hash_map<std::string, Value>)->RangeMultiplier(2)->Range(down, up);

BENCHMARK_MAIN();
