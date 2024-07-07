#include <stdio.h>
#include "ExcludedElements.h"

ExcludedElements::ExcludedElements(const int32_t* elements,size_t size) : Elements(elements,size){}


bool ExcludedElements::operator()(int32_t element) const{
    for(int i = 0;i<size;i++){
        if(element == elements[i])
            return false;
    }
    return true;
}

