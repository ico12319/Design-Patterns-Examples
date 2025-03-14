#include "FarmFactory.h"

class Farm{
    
private:
    Animal** animals;
    size_t count;
    size_t capacity;
    
    void copy(const Farm& other);
    void move(Farm&& other);
    void destroy();
    void resize(size_t newCap);
    
public:
    Farm();
    Farm(const Farm& other);
    Farm(Farm&& other);
    Farm& operator=(const Farm& other);
    Farm& operator=(Farm&& other);
    ~Farm();
    
    AnimalType getType(size_t index) const;
    void addAnimal(const AnimalType& type);
    void printFarm() const;
    void removeAnimal(const AnimalType& type);
    
};
