#include <stdio.h>
#include "CraftSetEvenNumbers.h"
#include "IncludedElements.h"
#include "SetByCriteria.hpp"



static size_t getEvenNumbersCount(){
    size_t count = 0;
    for(int i = 0;i<INT32_MAX;i++){
        if(i % 2 == 0)
            count++;
    }
    return count;
}

static void fillArrayWithEvenValues(int32_t* arr){
    int index = 0;
    for(int i = 0;i<INT32_MAX;i++){
        if(i % 2 == 0){
            arr[index] = i;
            index++;
        }
    }
}

Set* craftEvenSet(){
    size_t evenNumbersCount = getEvenNumbersCount();
    int32_t* elements = new int32_t[evenNumbersCount];
    fillArrayWithEvenValues(elements);
    IncludedElements included(elements,evenNumbersCount);
    Set* toReturn = new SetByCriteria<IncludedElements>(included);
    delete[] elements;
    return toReturn;
}
