/**
 * @brief Example of std::future in a thread pool.
 * 
 * @author Erik Zenker
 *
 */

#include <future>
#include <iostream>
#include <queue>
#include <chrono>
#include <tuple>


template <class R, class A>
std::vector<R> pool(R (*foo)(A), std::queue<A> args, unsigned maxThreads){
  std::chrono::milliseconds span(100);
  std::queue<std::future<R>> futures;
  std::vector<R> results;

  while(args.size() or futures.size()){
    // Queue work
    if((futures.size() < maxThreads) and !args.empty()){
      A arg = args.front();
      args.pop();
      futures.push(std::async(std::launch::async, foo, arg));
    }
    // Poll for finished work
    else {
      while(futures.size()){    
	std::future<R> f = std::move(futures.front());
	futures.pop();
	if(f.wait_for(span) == std::future_status::ready){
	  R a = f.get();
	  results.push_back(a);
	  break;
	  
	}
	else {
	  futures.push(std::move(f));

	}
    
      }      

    }

  }
  
  return results;
}


// Threaded function
int add(std::tuple<int, int> t){
  int a,b;
  std::tie(a,b) = t;
  return a+b;
}

int main(){

  // Add summands
  std::queue<std::tuple<int, int>> summands;
  summands.push(std::make_tuple(1,1));
  summands.push(std::make_tuple(2,2));
  summands.push(std::make_tuple(3,3));
  summands.push(std::make_tuple(4,4));

  unsigned numberOfThreads = 4;
  
  // Start thread pool
  std::vector<int> results = pool(add, summands, numberOfThreads);

  for(int i: results){
    std::cout << i << std::endl;
  }

  return 0;
}
