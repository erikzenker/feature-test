#include <benchmark/benchmark.h>

#include <string>
#include <cstring>
#include <set>

// compile: g++ main.cpp -lbenchmark

////////////////////////////////////////////////////////////////////////////////
static void BM_StringCreation(benchmark::State& state) {
  while (state.KeepRunning())
    std::string empty_string;
}
BENCHMARK(BM_StringCreation);

///////////////n/////////////////////////////////////////////////////////////////
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  while (state.KeepRunning())
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

////////////////////////////////////////////////////////////////////////////////
static void BM_memcpy(benchmark::State& state) {
  char* src = new char[state.range(0)];
  char* dst = new char[state.range(0)];
  std::memset(src, 'x', state.range(0));
  while (state.KeepRunning())
      std::memcpy(dst, src, state.range(0));
  state.SetBytesProcessed(int64_t(state.iterations()) *
                          int64_t(state.range(0)));
  delete[] src;
  delete[] dst;
}
BENCHMARK(BM_memcpy)->Range(8, 8<<10);

////////////////////////////////////////////////////////////////////////////////
static void BM_StringCompare(benchmark::State& state) {
  std::string s1(state.range(0), '-');
  std::string s2(state.range(0), '-');
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(s1.compare(s2));
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_StringCompare)
    ->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();


BENCHMARK_MAIN();
