#include <stdio.h>
#include "Function.h"

Function::Function(const int32_t* points,size_t count){
    
    this->points = new int32_t[count];
    for(int i = 0;i<count;i++){
        this->points[i] = points[i];
    }
    this->count = count;
}

Function::Function(const Function& other){
    copy(other);
}

Function::Function(Function&& other){
    move(std::move(other));
}

Function::~Function(){
    destroy();
}

Function& Function::operator=(const Function& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

Function& Function::operator=(Function&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}


void Function::destroy(){
    delete[]points;
    points = nullptr;
}

void Function::move(Function&& other){
    this->points = other.points;
    other.points = nullptr;
    this->count = other.count;
    other.count = 0;
}

void Function::copy(const Function& other){
    this->points = new int32_t[other.count];
    for(int i = 0;i<other.count;i++){
        this->points[i] = other.points[i];
    }
    this->count = other.count;
}
