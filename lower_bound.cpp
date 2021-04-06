#include <algorithm>
#include <map>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>
#include <absl/container/btree_map.h>


std::vector<uint64_t> gen(size_t n)
{
	std::vector<uint64_t> v;
	v.reserve(n);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<uint64_t> d(1, 1 << 31);
	for (size_t i = 0; i < n; ++i)
	{
		v.emplace_back(d(gen));
	}
	return v;
}

template <typename M>
void MapLowerBoundLookup(benchmark::State &state)
{
	size_t n = (size_t)state.range(0);
	auto v = gen(n);
	M m;
	std::for_each(std::begin(v), std::end(v), [&m](auto i) {
		m.emplace(i, typename M::key_type());
	});
	state.counters["actual_size"] = m.size();
	for (auto _ : state)
	{
		benchmark::DoNotOptimize(m.lower_bound(v[0]));
		benchmark::DoNotOptimize(m.lower_bound(v[1]));
		benchmark::DoNotOptimize(m.lower_bound(v[2]));
		benchmark::DoNotOptimize(m.lower_bound(v[n - 1]));
		benchmark::DoNotOptimize(m.lower_bound(v[n - 2]));
	}
}

using Vector = std::vector<std::string>;

void VectorLowerBoundLookup(benchmark::State &state)
{
	size_t n = (size_t)state.range(0);
	auto v = gen(n);
	std::vector<std::pair<uint64_t, Vector>> m;
	std::for_each(std::begin(v), std::end(v), [&m](auto i) {
		m.emplace_back(std::make_pair(i, Vector()));
	});
	std::sort(std::begin(m), std::end(m));

	auto cmp = [](const auto& pair, auto value) -> bool {
		return pair.first < value;
	}; 
	state.counters["actual_size"] = m.size();
	for (auto _ : state)
	{
		benchmark::DoNotOptimize(std::lower_bound(std::begin(m), std::end(m), v[0], cmp));
		benchmark::DoNotOptimize(std::lower_bound(std::begin(m), std::end(m), v[1], cmp));
		benchmark::DoNotOptimize(std::lower_bound(std::begin(m), std::end(m), v[2], cmp));
		benchmark::DoNotOptimize(std::lower_bound(std::begin(m), std::end(m), v[n - 1], cmp));
		benchmark::DoNotOptimize(std::lower_bound(std::begin(m), std::end(m), v[n - 2], cmp));
	}
}


constexpr auto down = 1 << 10;
constexpr auto up = 1 << 16;


BENCHMARK_TEMPLATE(MapLowerBoundLookup, std::map<uint64_t, Vector>)->RangeMultiplier(2)->Range(down, up);
BENCHMARK_TEMPLATE(MapLowerBoundLookup, absl::btree_map<uint64_t, Vector>)->RangeMultiplier(2)->Range(down, up);
BENCHMARK(VectorLowerBoundLookup)->RangeMultiplier(2)->Range(down, up);
BENCHMARK_MAIN();