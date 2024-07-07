#include <stdio.h>
#include "MaximumPartialFunction.h"


MaximumPartialFunction::MaximumPartialFunction() : MaximumOrMinimum(){}

MaximumPartialFunction::MaximumPartialFunction(PartialFunction** functions,size_t                   count):MaximumOrMinimum(functions,count){}

int32_t MaximumPartialFunction::operator()(int32_t point) const{
    int32_t max = functions[0]->operator()(point);
    for(int i = 0;i<count;i++){
        int32_t curr = functions[i]->operator()(point);
        if(curr > max)
            max = curr;
    }
    return max;
}

PartialFunction* MaximumPartialFunction::clone() const{
    return new MaximumPartialFunction(*this);
}


