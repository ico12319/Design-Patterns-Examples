#include <stdio.h>
#include "Type2.h"

Type2::Type2(const int32_t* points,size_t count) : Function(points, count){}

bool Type2::isPointExcluded(int32_t point) const{
    return false;
}

Pair Type2::operator()(int32_t point) const{
    int32_t value = 0;
    
    for(int i = 0;i<count;i++){
        if(point == points[i]){
            value = 1;
        }
    }
    return Pair(true, value);
}
