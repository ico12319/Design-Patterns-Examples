#include <stdio.h>
#include "Type1.h"


Type1::Type1(const int32_t* points,size_t count) : Function(points, count){}

bool Type1::isPointExcluded(int32_t point) const{
    for(int i = 0;i<count;i++){
        if(points[i] == point)
            return true;
    }
    return false;
}

Pair Type1::operator()(int32_t point) const{
    if(!isPointExcluded(point))
        return Pair(true, point);
    throw std::invalid_argument("The function is not defined in this point!");
}
