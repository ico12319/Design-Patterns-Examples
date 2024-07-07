#include "Cat.h"

class Cow : public Animal{
    
public:
    virtual void makeNoise() const override;
    Animal* clone() const override;
    AnimalType getType() const override;
    
};
