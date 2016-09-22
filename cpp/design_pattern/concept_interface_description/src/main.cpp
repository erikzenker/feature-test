/**
 * @author Erik Zenker
 * @compile g++ main.cpp -fconcepts
 * @online http://stackoverflow.com/questions/39622051/using-delete-for-interface-description/39626670?noredirect=1#comment66566955_39626670
 * @license GPLv3+
 *
 * @brief Demonstrates interface description by concepts
 *
 */

#include <iostream>
#include <type_traits>

// Concept description (currently only available on gcc 6+)
#if __GNUC__ >= 6
template <class T>
concept bool Animal() { 
    return requires(const T& a) {
        {a.sound()} -> std::string;
    }
    && std::is_class<typename T::Type>::value;
}
#else
#error "Concepts are only implemented by gcc 6+ up to now."
#endif

class Cat {
public:
    // Models the Animal concept
    std::string sound() const {
        return std::string("Meow");
    }

    using Type = Cat;
    
};

class Car {
public:
    // Does not implement the sound method
    std::string wrongSound() const {
        return std::string("Brum");
    }
};

void listenTo(Animal const & a ) {
    std::cout << a.sound() << std::endl;
}

int main(){

    // Cats and Dogs behave like IAnimals
    Animal cat = Cat();
    Car car;

    listenTo(cat);

    // A car is not a model of the Animal concept -> compile error
    // listenTo(car);
    
    return 0;
}
