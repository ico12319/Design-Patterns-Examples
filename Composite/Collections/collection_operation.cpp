#include "collection_operation.h"

collection_operation::collection_operation(collection* left,collection* right) : left(left->clone()),right(right->clone()){}

collection_operation::collection_operation(const collection_operation& other){
    copy(other);
}

collection_operation::collection_operation(collection_operation&& other){
    move(std::move(other));
}

collection_operation::~collection_operation(){
    destroy();
}

void collection_operation::destroy(){
    delete left;
    delete right;
}

void collection_operation::copy(const collection_operation& other){
    this->left = other.left->clone();
    this->right = other.right->clone();
}

void collection_operation::move(collection_operation&& other){
    this->left = other.left;
    this->right = other.right;
    
    other.left = other.right = nullptr;
}

collection_operation& collection_operation::operator=(const collection_operation& other){
    if(this != &other){
        destroy();
        copy(other);
    }
    return *this;
}

collection_operation& collection_operation::operator=(collection_operation&& other){
    if(this != &other){
        destroy();
        move(std::move(other));
    }
    return *this;
}
