#include <stdio.h>
#include "GiftsInterface.h"

GiftsInterface::GiftsInterface(){
    this->capacity = 8;
    this->gifts = new GiftBase*[this->capacity];
    this->size = 0;
}


GiftsInterface::GiftsInterface(const GiftBase** gifts,size_t size){
    this->gifts = new GiftBase*[size];
    for(int i = 0;i<size;i++)
        this->gifts[i] = gifts[i]->clone();
    this->size = this->capacity = size;
}

GiftsInterface::GiftsInterface(const GiftsInterface& other){
    copy(other);
}

GiftsInterface::GiftsInterface(GiftsInterface&& other){
    move(std::move(other));
}

GiftsInterface::~GiftsInterface(){
    destroy();
}

GiftsInterface& GiftsInterface::operator=(const GiftsInterface& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

GiftsInterface& GiftsInterface::operator=(GiftsInterface&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

void GiftsInterface::add(GiftBase* gift){
    if(size == capacity)
        resize(capacity * 2);
    if(gift == nullptr)
        throw std::invalid_argument("Invalid gift!");
    
    gifts[size] = gift;
    size++;
}

void GiftsInterface::remove(size_t index){
    if(index >= size)
        throw std::invalid_argument("Index out of bounds!");
    delete gifts[index];
    gifts[index] = nullptr;
    for(size_t i = index;i<size - 1;i++)
        gifts[index] = gifts[index + 1];
    size--;
}

void GiftsInterface::destroy(){
    for(int i = 0;i<size;i++)
        delete gifts[i];
    delete[] gifts;
}


void GiftsInterface::move(GiftsInterface&& other){
    this->gifts = other.gifts;
    this->capacity = other.capacity;
    this->size = other.size;
    other.gifts = nullptr;
    other.capacity = other.size = 0;
}


void GiftsInterface::copy(const GiftsInterface& other){
    this->gifts = new GiftBase*[other.capacity];
    for(int i = 0;i<other.size;i++)
        this->gifts[i] = other.gifts[i]->clone();
    this->size = other.size;
    this->capacity = other.capacity;
}

void GiftsInterface::resize(size_t newCap){
    GiftBase** temp = new GiftBase*[newCap];
    for(int i = 0;i<size;i++)
        temp[i] = gifts[i];
    delete[] gifts;
    gifts = temp;
    this->capacity = newCap;
}
