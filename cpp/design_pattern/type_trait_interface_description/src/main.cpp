/**
 * @author Erik Zenker
 * @compile g++ main.cpp
 * @license GPLv3+
 *
 * @brief Demonstrates interface description by type traits
 *
 */

#include <iostream>
#include <type_traits>
#include <experimental/type_traits>


// Describe the Animal interface by type traits
template <typename T>
using sound_type = decltype(std::declval<const T&>().sound());

template <typename T>
using has_sound = std::experimental::is_detected<sound_type, T>;

template <typename T>
using is_animal = has_sound<T>;
//using is_animal = std::conditional_t<has_sound<T>::value /*&& other_conditions */,
//                                     std::true_type, std::false_type>;


class Cat {
public:
    // Models the Animal concept
    std::string sound() const {
        return std::string("Meow");
    }
};


class Car {
public:
    // Does not implement the sound method
    std::string wrongSound() const {
        return std::string("Brum");
    }
};


template<class TAnimal, 
         typename = std::enable_if_t<is_animal<TAnimal>::value> >
void listenTo(TAnimal const & a ) {
    std::cout << a.sound() << std::endl;
}


int main(){

    // Cats and Dogs behave like IAnimals
    Cat cat;
    Car car;

    listenTo(cat);

    // A car does fulfil the is_animal trait --> compile time error
    // listenTo(car);
    
    return 0;
}
