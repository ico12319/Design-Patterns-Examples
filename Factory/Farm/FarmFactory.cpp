#include <stdio.h>
#include "FarmFactory.h"

Animal* farmFactory(const AnimalType& type){
    if(type == AnimalType::DOG){
        return new Dog();
    }
    else if(type == AnimalType::CAT){
        return new Cat();
    }
    else if(type == AnimalType::COW){
        return new Cow();
    }
    return nullptr;
}
