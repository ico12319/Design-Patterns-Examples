#include <stdio.h>
#include "SetOperation.h"

SetOperation::SetOperation(){
    this->capacity = 8;
    this->sets = new Set*[this->capacity];
    this->count = 0;
}

SetOperation::SetOperation(Set** sets,size_t count){
    this->sets = new Set*[count];
    for(int i = 0;i<count;i++)
        this->sets[i] = sets[i]->clone();
    this->count = count;
    this->capacity = count;
}

SetOperation::SetOperation(const SetOperation& other){
    copy(other);
}

void SetOperation::copy(const SetOperation& other){
    this->sets = new Set*[other.capacity];
    for(int i = 0;i<other.count;i++)
        this->sets[i] = other.sets[i]->clone();
    this->count = other.count;
    this->capacity = other.capacity;
}

SetOperation::SetOperation(SetOperation&& other){
    move(std::move(other));
}

SetOperation::~SetOperation(){
    destroy();
}

void SetOperation::destroy(){
    for(int i = 0;i<count;i++)
        delete sets[i];
    delete[] sets;
}

void SetOperation::move(SetOperation&& other){
    this->sets = other.sets;
    other.sets = nullptr;
    this->count = other.count;
    this->capacity = other.capacity;
    other.count = other.capacity = 0;
}



void SetOperation::resize(size_t newCap){
    Set** temp = new Set*[newCap];
    for(int i = 0;i<count;i++)
        temp[i] = sets[i];
    delete[]sets;
    sets = temp;
    capacity = newCap;
}

void SetOperation::addSet(Set* set){
    if(count > capacity)
        resize(capacity * 2);
    sets[count] = set;
    count++;
}

SetOperation& SetOperation::operator=(const SetOperation& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

SetOperation& SetOperation::operator=(SetOperation&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}
