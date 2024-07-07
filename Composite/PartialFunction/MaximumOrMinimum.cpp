#include <stdio.h>
#include "MaximumOrMinimum.h"

MaximumOrMinimum::MaximumOrMinimum(){
    this->capacity = 8;
    this->functions = new PartialFunction*[this->capacity];
    this->count = 0;
}

MaximumOrMinimum::MaximumOrMinimum(PartialFunction** functions,size_t count){
    this->functions = new PartialFunction*[count];
    for(int i = 0;i<count;i++){
        this->functions[i] = functions[i]->clone();
    }
    this->count = count;
}

MaximumOrMinimum::MaximumOrMinimum(const MaximumOrMinimum& other){
    copy(other);
}

MaximumOrMinimum::MaximumOrMinimum(MaximumOrMinimum&& other){
    move(std::move(other));
}

MaximumOrMinimum::~MaximumOrMinimum(){
    destroy();
}

void MaximumOrMinimum::destroy(){
    for(int i = 0;i<count;i++)
        delete functions[i];
    delete[] functions;
}

void MaximumOrMinimum::copy(const MaximumOrMinimum& other){
    this->functions = new PartialFunction*[other.capacity];
    for(int i = 0;i<other.count;i++)
        this->functions[i] = other.functions[i]->clone();
    this->capacity = other.capacity;
    this->count = other.count;
}

void MaximumOrMinimum::move(MaximumOrMinimum&& other){
    this->functions = other.functions;
    other.functions = nullptr;
    this->count = other.count;
    this->capacity = other.capacity;
    this->count = other.count = 0;
}


void MaximumOrMinimum::resize(size_t newCap){
    PartialFunction** temp = new PartialFunction*[newCap];
    for(int i = 0;i<count;i++)
        temp[i] = functions[i];
    delete[]functions;
    functions = temp;
    capacity = newCap;
}


void MaximumOrMinimum::add(PartialFunction* function){
    if(count == capacity)
        resize(capacity * 2);
    functions[count] = function;
    count++;
}


bool MaximumOrMinimum::isDefined(int32_t point) const{
    for(int i = 0;i<count;i++){
        if(!functions[i]->isDefined(point))
            return false;
    }
    return true;
}
