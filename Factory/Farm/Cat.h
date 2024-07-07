#include "Dog.h"

class Cat : public Animal{
    
    
public:
    virtual void makeNoise() const override;
    Animal* clone() const override;
    AnimalType getType() const override;
};
