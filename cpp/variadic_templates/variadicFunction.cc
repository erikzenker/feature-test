#include <iostream>
#include <vector>
#include <array>

// Function iterator
template <typename Head>
void iterateFunctions(const std::vector<bool> doPrint, const unsigned depth){
    if(doPrint.at(depth))
	std::cout << Head::print() << std::endl;

}

template <typename Head, typename Head2, typename... Tail>
void iterateFunctions(const std::vector<bool> doPrint, const unsigned depth){
    if(doPrint.at(depth))
	std::cout << Head::print() << std::endl;

    iterateFunctions<Head2, Tail...>(doPrint, depth + 1);
}

// Functions
struct one {
    static std::string print(){
	return "one";
    }
};

struct two {
    static std::string print(){
	return "two";
    }
};

struct three {
    static std::string print(){
	return "three";
    }

    
};


// Main
int main(){
    std::vector<bool> doPrint {true, false, false};

    iterateFunctions<one, two, three >(doPrint, 0);


    return 0;


}
