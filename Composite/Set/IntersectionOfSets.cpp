#include <stdio.h>
#include "IntersectionOfSets.h"


IntersectionOfSets::IntersectionOfSets() : SetOperation(){}

IntersectionOfSets::IntersectionOfSets(Set** sets,size_t count) : SetOperation(sets, count){}

bool IntersectionOfSets::isContained(int32_t element) const{
    for(int i = 0;i<count;i++){
        if(!sets[i]->isContained(element))
            return false;
    }
    return true;
}


Set* IntersectionOfSets::clone() const{
    return new IntersectionOfSets(*this);
}
