#include <stdio.h>
#include "UnionOfSets.h"


UnionOfSets::UnionOfSets() : SetOperation(){}

UnionOfSets::UnionOfSets(Set** sets,size_t count) : SetOperation(sets,count){}

bool UnionOfSets::isContained(int32_t element) const{
    for(int i = 0;i<count;i++){
        if(sets[i]->isContained(element))
            return true;
    }
    return false;
}


Set* UnionOfSets::clone() const{
    return new UnionOfSets(*this);
}
