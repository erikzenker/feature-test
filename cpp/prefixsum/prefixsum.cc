#include <algorithm>
#include <iostream>
#include <vector>



template <class T>
struct exclusiveScan {

    T value;
    
    exclusiveScan(T init) : value(init){}

    void operator()(T &n){
	T prevValue = value;
	value += n;
	n = prevValue;
    }
    
};



template <class InputIterator>
void prefixsum(InputIterator first, InputIterator last){

  typedef typename std::iterator_traits<InputIterator>::value_type IterType;
  
  IterType value = 0;
  std::for_each(first, last, [&value]
		(IterType &n){
		  IterType prevValue = value;
		  value += n;
		  n = prevValue;
		});

}

template <class InputIterator, class OutputIterator>
void prefixsum(InputIterator first, InputIterator last, OutputIterator result){

  typedef typename std::iterator_traits<InputIterator>::value_type IterType;
  
  
  IterType value = 0;
  std::for_each(first, last, [&value, &result]
		(IterType &n){
		  IterType prevValue = value;
		  value += n;
		  *result = prevValue;
		  result++;
		});

}


int main(){

  std::vector<unsigned> input {1,2,3,4,5};
  std::vector<unsigned> output (input.size(),0);

  for_each(input.begin(), input.end(), exclusiveScan<unsigned>(0));

  for(int i:input)
      std::cout << i << std::endl;
  
  return 0;
}
