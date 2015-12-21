// CLIB
#include <cassert>

// STL
#include <condition_variable>
#include <mutex>
#include <queue>

// COMPILE: g++ ConcurrentQueue.cpp -std=c++11


template<typename Data>
class ConcurrentQueue
{
private:
    std::queue<Data> queue;
    std::mutex mutex;
    std::condition_variable condition;
    
public:
    void push(Data const& data){
	{
	    std::lock_guard<std::mutex> lock(mutex);
	    queue.push(data);
	}
        condition.notify_one();
    }

    bool empty(){
	std::lock_guard<std::mutex> lock(mutex);
        return queue.empty();
    }

    bool try_pop(Data& value) {
	std::lock_guard<std::mutex> lock(mutex);
        if(queue.empty()){
	    return false;
	}
        
        value=queue.front();
        queue.pop();
        return true;
    }

    Data& wait_and_pop(){
	std::unique_lock<std::mutex> lock(mutex);
        while(queue.empty()){
	    condition.wait(lock);
	}
        
        Data& value=queue.front();
        queue.pop();
	return value;
	
    }

};


int main(){


    ConcurrentQueue<int> q;

    assert(q.empty() == true);
    
    q.push(1);
    q.push(2);
    q.push(3);

    assert(q.empty() == false);

    assert(q.wait_and_pop() == 1);
    assert(q.wait_and_pop() == 2);
    assert(q.wait_and_pop() == 3);

    assert(q.empty() == true);
    

}
