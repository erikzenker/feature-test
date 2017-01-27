#include <functional>
#include <iostream>
#include <typeinfo>
#include<boost/type_index.hpp>

// compile: g++ main.cpp --std=c++11

using boost::typeindex::type_id_with_cvr;

template <typename Function>
struct function_traits
{};

template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType(ClassType::*)(Args...) const>
{
    typedef ReturnType (*pointer)(Args...);
    typedef std::function<ReturnType(Args...)> function;
};

template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType(*(ClassType))(Args...) const>
{
    typedef ReturnType (*pointer)(Args...);
    typedef std::function<ReturnType(Args...)> function;
};

template <typename T>
void foo(T t){
    std::cout << "other function" << std::endl;
    using F = decltype(&T::operator());
    std::cout << "decltype(b()) is " << type_id_with_cvr<F>().pretty_name() << '\n'; 
}

template <typename T>
void foo(std::_Bind<T> b){
    std::cout << "bind" << std::endl;
    std::cout << "T is " << type_id_with_cvr<T>().pretty_name() << '\n'; 
    using F = decltype(b(1));

    typename function_traits<T>::function f;
    
     foo([f](){
	     f(1);
     	});
    //std::cout << "decltype(b()) is " << type_id_with_cvr<F>().pretty_name() << '\n'; 
}

int test(int arg){
    std::cout << "test" << std::endl;
    return 0;
}

int main(){

    foo(std::bind(test, std::placeholders::_1));

    return 0;
}
