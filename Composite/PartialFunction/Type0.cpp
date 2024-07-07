#include <stdio.h>
#include "Type0.h"

Type0::Type0(const int32_t* points,size_t count,const int32_t* results) : Function(points, count){
    this->results = new int32_t[count];
    for(int i = 0;i<count;i++)
        this->results[i] = results[i];
}

Type0::Type0(const Type0& other) : Function(other){
    copy(other);
}

Type0::Type0(Type0&& other) : Function(other){
    move(std::move(other));
}

Type0& Type0::operator=(const Type0& other){
    if(this!=&other){
        Function::operator=(other);
        destroy();
        copy(other);
    }
    return *this;
}

Type0& Type0::operator=(Type0&& other){
    if(this!=&other){
        Function::operator=(std::move(other));
        destroy();
        move(std::move(other));
    }
    return *this;
}

void Type0::destroy(){
    delete[] results;
    results = nullptr;
}

void Type0::copy(const Type0& other){
    this->results = new int32_t[other.count];
    for(int i = 0;i<other.count;i++){
        this->results[i] = other.results[i];
    }
}

void Type0::move(Type0&& other){
    this->results = other.results;
    other.results = nullptr;
}


bool Type0::isPointExcluded(int32_t point) const{
    for(int i = 0;i<count;i++){
        if(point == points[i]){
            return false;
        }
    }
    return true;
}

Pair Type0::operator()(int32_t point) const{
    
    int32_t value = 0;
    for(int i = 0;i<count;i++){
        if(point == points[i]){
            value = results[i];
        }
    }
    return Pair(!isPointExcluded(point), value);
}

Type0::~Type0(){
    destroy();
}


