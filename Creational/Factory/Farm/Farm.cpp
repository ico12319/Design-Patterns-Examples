#include <stdio.h>
#include "Farm.h"


Farm::Farm(){
    this->animals = new Animal*[8];
    this->count = 0;
    this->capacity = 8;
}

Farm::Farm(const Farm& other){
    copy(other);
}

Farm::Farm(Farm&& other){
    move(std::move(other));
}

Farm& Farm::operator=(const Farm& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

Farm& Farm::operator=(Farm&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

Farm::~Farm(){
    destroy();
}

void Farm::copy(const Farm& other){
    this->animals = new Animal*[other.capacity];
    for(int i = 0;i<other.count;i++)
        this->animals[i] = other.animals[i]->clone();
    this->count = other.count;
    this->capacity = other.capacity;
    
}

void Farm::move(Farm&& other){
    this->animals = other.animals;
    other.animals = nullptr;
    this->count = other.count;
    other.count = 0;
}


void Farm::destroy(){
    for(int i = 0;i<count;i++)
        delete animals[i];
    delete[]animals;
}


void Farm::addAnimal(const AnimalType& type){
    
    if(count > capacity)
        resize(capacity * 2);
    animals[count] = farmFactory(type);
    count++;
}

void Farm::printFarm() const{
    for(int i =  0;i<count;i++){
        std::cout<<animals[i]->getType()<<": ";
        animals[i]->makeNoise();
    }
}


void Farm::removeAnimal(const AnimalType& type){
    for(int i = 0;i<count;i++){
        if(animals[i]->getType() == type){
            for(int j = i;j<count - 1;j++){
                animals[i] = animals[i+1]->clone();
            }
        }
    }
}


void Farm::resize(size_t newCap){
    Animal** temp = new Animal*[newCap];
    for(int i = 0;i<count;i++){
        temp[i] = animals[i]->clone();
    }
    delete[]animals;
    animals = temp;
    capacity = newCap;
}


AnimalType Farm::getType(size_t index) const{
    return animals[index]->getType();
}
