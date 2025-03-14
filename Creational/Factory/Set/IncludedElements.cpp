#include <stdio.h>
#include "IncludedElements.h"


IncludedElements::IncludedElements(const int32_t* elements,size_t size) : Elements(elements,size){}

bool IncludedElements::operator()(int32_t element) const{
    for(int i = 0;i<size;i++){
        if(element == elements[i]){
            return true;
        }
    }
    return false;
}
