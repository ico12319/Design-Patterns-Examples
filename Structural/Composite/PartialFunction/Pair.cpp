#include <stdio.h>
#include "Pair.h"

Pair::Pair(bool isDefined,int32_t value){
    this->isDefined = isDefined;
    this->value = value;
}

int32_t Pair::getValue() const{
    return value;
}

bool Pair::getIsDefined() const{
    return isDefined;
}
