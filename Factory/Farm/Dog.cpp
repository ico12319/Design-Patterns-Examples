#include "Dog.h"

void Dog::makeNoise() const{
    std::cout<<"Bark!, Bark!"<<std::endl;
}

Animal* Dog::clone() const{
    return new Dog(*this);
}

AnimalType Dog::getType() const{
    return AnimalType::DOG;
}
