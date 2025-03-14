#include <stdio.h>
#include "Cat.h"


void Cat::makeNoise() const{
    std::cout<<"Meow, meow"<<std::endl;
}

Animal* Cat::clone() const{
    return new Cat(*this);
}

AnimalType Cat::getType() const{
    return AnimalType::CAT;
}


