#include <benchmark/benchmark.h>

#include <atomic>
#include <mutex>


//compile: g++ main.cpp -fgnu-tm -lbenchmark

static void TransactionalMemoryIncBenchmark(benchmark::State& state) {
    static int i = 0;
    while (state.KeepRunning()){
	for(std::size_t i = 0; i < state.range(0); ++i){
	    synchronized { 
		++i;       
	    }
	}

    }
}
BENCHMARK(TransactionalMemoryIncBenchmark)->Threads(100)->Threads(1000)->Range(1<<10, 1<<20);


static void AtomicIncBenchmark(benchmark::State& state) {
    static std::atomic<int> i(0);
    while (state.KeepRunning()){
	for(std::size_t i = 0; i < state.range(0); ++i){
	    ++i;       
	}
    }
}
BENCHMARK(AtomicIncBenchmark)->Threads(100)->Threads(1000)->Range(1<<10, 1<<20);

static void MutexIncBenchmark(benchmark::State& state) {
    static int i(0);
    static std::mutex m;
    while (state.KeepRunning()){
	for(std::size_t i = 0; i < state.range(0); ++i){
	    std::lock_guard<std::mutex> lock(m);
	    ++i;
	}
    }
}
BENCHMARK(MutexIncBenchmark)->Threads(100)->Threads(1000)->Range(1<<10, 1<<20);


BENCHMARK_MAIN();
