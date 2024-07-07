#include <stdio.h>
#include "MinimumPartialFunction.h"



MinimumPartialFunction::MinimumPartialFunction() : MaximumOrMinimum(){}

MinimumPartialFunction::MinimumPartialFunction(PartialFunction** fucntions,size_t count) : MaximumOrMinimum(fucntions, count){}

int32_t MinimumPartialFunction::operator()(int32_t point) const{
    int32_t min = functions[0]->operator()(point);
    for(int i = 0;i<count;i++){
        int32_t curr = functions[i]->operator()(point);
        if(curr < min)
            min = curr;
    }
    return min;
}

PartialFunction* MinimumPartialFunction::clone() const{
    return new MinimumPartialFunction(*this);
}
