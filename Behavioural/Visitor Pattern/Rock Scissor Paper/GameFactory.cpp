#include <stdio.h>
#include "GameFactory.h"


GameFactory::GameFactory(){
    this->capacity = 8;
    this->data = new Type*[this->capacity];
    this->size = 0;
}


GameFactory::GameFactory(const GameFactory& other){
    copy(other);
}

GameFactory::GameFactory(GameFactory&& other) noexcept{
    move(std::move(other));
}


GameFactory& GameFactory::operator=(const GameFactory& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

GameFactory& GameFactory::operator=(GameFactory&& other) noexcept{
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}


void GameFactory::destroy(){
    for(int i = 0;i<size;i++){
        delete data[i];
    }
    delete[]data;
}

void GameFactory::copy(const GameFactory& other){
    this->capacity = other.capacity;
    this->data = new Type*[other.capacity];
    for(int i = 0;i<other.capacity;i++){
        this->data[i] = other.data[i] -> clone();
    }
    this->size = other.size;
}

void GameFactory::move(GameFactory&& other){
    this->data = other.data;
    other.data = nullptr;
    
    this->size = other.size;
    this->capacity = other.capacity;
    other.capacity = other.size = 0;
}
void GameFactory::resize(size_t newCap){
    Type** tempArr = new Type*[newCap];
    for(int i = 0;i<size;i++){
        tempArr[i] = data[i];
    }
    delete[]data;
    data = tempArr;
    capacity = newCap;
}

GameFactory::~GameFactory(){
    destroy();
}

void GameFactory::addPlayer(Type* type){
    if(type == nullptr)
        throw std::invalid_argument("Trying to access nullptr");
    
    if(size == capacity)
        resize(capacity * 2);
    data[size] = type;
    size++;
}

void GameFactory::addPlayer(const Type& type){
    
    Type* cloned = type.clone();
    addPlayer(cloned);
}

Output GameFactory::determineWinnerBetweenTwo(Type* lhs,Type* rhs){
    return lhs->beats(rhs);
}

Type* GameFactory::getPlayer(size_t index) const{
    if(index >= size)
        throw std::invalid_argument("Out of bounds!");
    return data[index];
}

void GameFactory::remove(size_t index){
    
    if(index >= size)
        throw std::invalid_argument("Invalid index!");
    
    delete data[index];
    data[index] = nullptr;
    for(size_t i = index;i<size - 1;i++){
        data[i] = data[i+1];
    }
    size--;
}


Type* GameFactory::determineWinner() {
    while (size > 1) {
        Output output = determineWinnerBetweenTwo(data[0], data[1]);
        if (output == Output::DRAW || output == Output::WIN){
            try{
                remove(1);
            }
            catch(const std::exception& e){
                std::cout<<e.what()<<std::endl;
            }
        }
        else if (output == Output::LOSS)
            try{
                remove(0);
            }
            catch(const std::exception& e){
                std::cout<<e.what()<<std::endl;
            }
    }
    return data[0];
}
