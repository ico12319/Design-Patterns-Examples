#include <stdio.h>
#include "Cow.h"

void Cow::makeNoise() const{
    std::cout<<"Muu, muu"<<std::endl;
}

Animal* Cow::clone() const{
    return new Cow(*this);
}

AnimalType Cow::getType() const{
    return AnimalType::COW;
}
