#include <stdio.h>
#include "Elements.h"


Elements::Elements(const int32_t* elements,size_t size){
    this->elements = new int32_t[size];
    for(int i = 0;i<size;i++)
        this->elements[i] = elements[i];
    this->size = size;
}

Elements::Elements(const Elements& other){
    copy(other);
}

Elements::Elements(Elements&& other){
    move(std::move(other));
}


Elements& Elements::operator=(const Elements& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

Elements& Elements::operator=(Elements&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

Elements::~Elements(){
    destroy();
}


void Elements::copy(const Elements& other){
    this->elements = new int32_t[other.size];
    for(int i = 0;i<other.size;i++)
        this->elements[i] = other.elements[i];
    this->size = other.size;
}

void Elements::move(Elements&& other){
    this->elements = other.elements;
    other.elements = nullptr;
    this->size = other.size;
    other.size = 0;
}

void Elements::destroy(){
    delete[]elements;
    elements = nullptr;
}
