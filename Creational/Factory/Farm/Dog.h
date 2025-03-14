#include <stdio.h>
#include "Animal.h"

class Dog : public Animal{
    

public:
    virtual void makeNoise() const override;
    virtual Animal* clone() const override;
    virtual AnimalType getType() const override;
};

