// USEFULL LINKS
// 
// http://stackoverflow.com/questions/257288/is-it-possible-to-write-a-c-template-to-check-for-a-functions-existence

// Compile : clang++ policy_member_check.cc -std=c++11

#include <iostream>    /* std::cout, std::endl */
#include <type_traits> /* std::enable_if */


// SFINAE test 
template <typename T>
class has_extendedFoo {
    typedef char one;
    typedef long two;

    template <typename C> static one test( decltype(&C::extendedFoo) ) ;
    template <typename C> static two test(...);


public:
    enum { value = sizeof(test<T>(0)) == sizeof(char) };
};

// POLICY1
struct Policy1 {

    void coreFoo(){
        std::cout << "core" << std::endl;
    }
    
};

// POLICY2
struct Policy2 {

    void coreFoo() {
        std::cout << "core" << std::endl;
    }

    void extendedFoo() {
        std::cout << "extended" << std::endl;
    }
    
};
    
// HOST
template <typename T_Policy>
struct Host : public T_Policy {

    void foo() {
        foo_detail<T_Policy>();
    }

    template<typename T>
    typename std::enable_if<has_extendedFoo<T>::value, int>::type
    foo_detail(){
        T::extendedFoo();
        return 0;
    }

    template<typename T>
    typename std::enable_if<!has_extendedFoo<T>::value, int>::type
    foo_detail(){
        T::coreFoo();
        return 0;
    }

};


int main(){

    Host<Policy1> core;
    Host<Policy2> extended;

    core.foo();
    extended.foo();
    

}
