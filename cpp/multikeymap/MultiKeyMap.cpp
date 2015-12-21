// CLIB
#include <cassert>

// STL
#include <iostream> /* std::cout, std::endl */
#include <string>   /* std::string */
#include <tuple>    /* std::tuple, std::get */
#include <vector>   /* std::vector */

// MultiKeyMap
#include <MultiKeyMap.hpp>

// HANA
#include <boost/hana.hpp>
namespace hana = boost::hana;

// COMPILE : g++ MultiKeyMap.cpp -std=c++14 -I hana/include/ -I .; ./a.out 


int main(){

    // Set types for keys and value
    typedef int         Key1;
    typedef float       Key2;
    typedef std::string Key3;
    typedef int         Value;

    // Create multi key map
    //MultiKeyMap<Value, Key1, Key2, Key3> map;

    MessageBox<Value, Key1, Key2, Key3> mb;


    mb.enqueue(1, 1, 0.5, "ha");
    mb.enqueue(2, 1, 0.5, "hi");
    mb.enqueue(3, 1, 0.5, "hu");    

    // Full key provided
    assert(mb.waitDequeue(1, 0.5, "ha") == 1);

    hana::tuple<Key1, Key2, Key3> keys;
    
    // Sub key provided
    assert(mb.waitDequeue(keys, 1, 0.5) == 2);
    assert(mb.waitDequeue(keys, 1) == 3);
    

    // Set some value
    // map(1, 0.5, "Hi") = 4;
    // map(1, 0.5, "Ho") = 5;
    // map(1, 0.6, "Ha") = 6;
    // map(2, 0.6, "Ha") = 7;


    // // Print some value
    // assert(map.test(1, 0.5, "Hey") == false);
    // assert(map.test(1, 0.5, "Hi") == true);
    // assert(map.at(1, 0.5, "Hi") == 4);

    // std::vector<Value > values;
    // std::vector<hana::tuple<Key1, Key2, Key3> > keys;
    
    // map.values(values, keys, 1);

    // assert(values.size() == 3);
    // assert(keys.size() == 3);    
    
    //assert(map.erase(keys.at(0)) == true);

    return 0;
}
    
