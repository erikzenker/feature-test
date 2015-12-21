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

// Threaded function
std::tuple<int, std::string> foo(std::string name){
  return std::make_tuple(42, name);
}


int main(){

  // Polling frequenc of 100ms
  std::chrono::milliseconds span(100);

  // Create threads and start them asyncron
  std::future<std::tuple<int, std::string>> a,b,c,d;
  a = std::async(std::launch::async, foo, "Erik");
  b = std::async(std::launch::async, foo, "Hendrik"); 
  c = std::async(std::launch::async, foo, "Carli");
  d = std::async(std::launch::async, foo, "Philip");

  // Queue futures
  std::queue<std::future<std::tuple<int, std::string>>> futures;
  futures.push(std::move(a));
  futures.push(std::move(b));
  futures.push(std::move(c));
  futures.push(std::move(d));
  
  while(futures.size()){    
    // Get next future
    std::future<std::tuple<int, std::string>> f = std::move(futures.front());
    futures.pop();

    // Check if feature finished
    if(f.wait_for(span) == std::future_status::ready){
      int digit;
      std::string name;
      std::tie(digit, name) = f.get();
      std::cerr << "Digit: " << digit << " Name: " << name << std::endl;
    }
    // If not finished push back to queue
    else {
      futures.push(std::move(f));

    }
    
  }

  return 0;

}
