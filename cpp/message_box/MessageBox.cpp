// STL
#include <condition_variable>
#include <mutex>
#include <queue>

// HANA
#include <boost/hana.hpp>



/*******************************************************************************
 * Message Box
 *******************************************************************************/
namespace hana = boost::hana;

template <typename T_Value, typename... T_Keys>
 class MessageBox {


    std::mutex mutex;
    std::condition_variable condition;
    
    // using Queue = std::queue<T_Value>
    // MultiKeyMap<, T_Keys...> multiKeyMap

    auto enqueue(T_Value&& value, const T_Keys... keys) -> void {
	{
	std::lock_guard<std::mutex> lock(mutex);
	// multiKeyMap(keys...).push(value);
	}
	condition.notify_one();
    }

    auto waitDequeue(const T_Keys... keys) -> T_Value& {
	std::unique_lock<std::mutex> lock(mutex);
	//auto queue& = multiKeyMap(keys...);
	//while(queue.empty()){
	//  condition.wait(lock);
	//}
	// T_Value& value = queue.front();
        // queue.pop();
	// return value;
    }

    template <typename... SubKeys>
    auto waitDequeue(const SubKeys... keys) -> T_Value& {
	std::unique_lock<std::mutex> lock(mutex);
	// bool foundValue = false;
	// while(!foundValue){
	//     std::vector<T_Value> values;
	//     while(multiKeyMap.values(values, keys).empty()){
	// 	condition.wait(lock);
	//     }

	//     for(auto &queue : values){
	// 	if(!queue.empty()) {
	// 	    T_Value& value = queue.front();
	// 	    queue.pop();
	// 	    return value;
	// 	}

	//     }
	//     condition.wait(lock);
	    
	// }
	
    }
     

 };

    
int main(){
    using Key1  = int;
    using Key2  = char;
    using Key3  = unsigned;
    using Value = int;
    
    MessageBox<Value, Key1, Key2, Key3> m;
    
    return 0;
}
