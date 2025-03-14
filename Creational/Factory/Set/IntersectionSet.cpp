#include <stdio.h>
#include "IntersectionSet.h"

Set* craftIntersectionSet(std::ifstream& ifs1,std::ifstream& ifs2){
    Set* set1 = craftEvenSet();
    Set* set2 = craftSetWithExcluedValues(ifs1);
    Set* set3 = craftSetWithIncluedValues(ifs2);
    SetOperation* toReturn = new IntersectionOfSets();
    toReturn->addSet(set1);
    toReturn->addSet(set2);
    toReturn->addSet(set3);
    return toReturn;
}
