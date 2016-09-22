/**
 * @author Erik Zenker
 * @compile g++ main.cpp
 * @online http://stackoverflow.com/questions/39622051/using-delete-for-interface-description/39626670?noredirect=1#comment66566955_39626670
 * @license GPLv3+
 *
 * @brief Demonstrates inheritance through deleted method
 *
 */

#include <iostream>
#include <type_traits>

class IAnimal {
public:
    // Interface that needs to be implemented
    std::string sound() const  = delete;
protected:
    IAnimal(){}
};


class Cat : public IAnimal {
public:
    Implements deleted method
    std::string sound() const {
        return std::string("Meow");
    }
    
};

class WildCat : public Cat {
public:
    // Overwrites Cat sound method
    std::string sound() const {
        return std::string("Rarr");
    }
    
};

class Dog : public IAnimal{
public:
    // Implements deleted method
    std::string sound() const {
        return std::string("Wuff");
    }
};


class Car {
public:
    // Implements deleted method
    std::string sound() const {
        return std::string("Brum");
    }
};



// Sfinae tests for proper inheritance
template<class TAnimal,
         typename = std::enable_if_t<std::is_base_of<IAnimal, TAnimal>::value> >
void listenTo(TAnimal const & a ) {
    std::cout << a.sound() << std::endl;
}


int main(){

    // Objects of type IAnimal can not be instanciated
    // IAnimal a;

    // Cats and Dogs behave like IAnimals
    Cat cat;
    WildCat wildCat;
    Dog dog;
    Car car;

    listenTo(cat);
    listenTo(wildCat);
    listenTo(dog);

    // A car is no animal -> compile time error
    // listenTo(car);
    
    return 0;
}
