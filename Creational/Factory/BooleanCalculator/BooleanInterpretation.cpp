#include <stdio.h>
#include "BooleanInterpretation.h"

void BooleanInterpretation::setValue(char symbol,bool value){
    symbolValues[symbol - 'a'] = value;
}

bool BooleanInterpretation::getValue(char symbol) const{
    return symbolValues[symbol - 'a'];
}


