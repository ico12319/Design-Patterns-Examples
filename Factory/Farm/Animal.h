#include "AnimalType.h"
#include <iostream>


class Animal{
    
public:
    Animal() = default;
    virtual void makeNoise() const = 0;
    virtual Animal* clone() const = 0;
    virtual AnimalType getType() const = 0;
    virtual ~Animal() = default;
    
};
