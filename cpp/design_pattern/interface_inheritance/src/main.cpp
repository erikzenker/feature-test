/**
 * @author Erik Zenker
 * @compile g++ main.cpp
 * @license GPLv3+
 *
 * @brief Demonstrates interface inheritance through pure abstract methods.
 *
 */

#include <iostream>

class Animal {

public:

    // Pure virtual method
    virtual std::string sound() const = 0;
    
};


class Cat : public Animal {

public:

    // Implements pure virtual method interface    
    virtual std::string sound() const override {
        return std::string("Meow");
    }
    
};


class Dog : public Animal {

public:

    // Implements pure virtual method interface
    virtual std::string sound() const override {
        return std::string("Wuff");
    }
};


void listenTo(Animal const * const a) {
    std::cout << a->sound() << std::endl;
}


int main(){

    Animal * a1 = new Cat;
    Animal * a2 = new Dog;

    listenTo(a1);
    listenTo(a2);

    return 0;
}
