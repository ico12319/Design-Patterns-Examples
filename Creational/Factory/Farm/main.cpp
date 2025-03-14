#include <iostream>
#include "Farm.h"

int main(int argc, const char * argv[]) {
    Farm farm;
    farm.addAnimal(AnimalType::DOG);
    farm.addAnimal(AnimalType::CAT);
    farm.addAnimal(AnimalType::COW);
    farm.addAnimal(AnimalType::CAT);

    farm.printFarm();
    
    farm.removeAnimal(AnimalType::CAT);
    
    farm.printFarm();
    
}
