#include <stdio.h>
#include "BinaryOperation.h"


BinaryOperation::BinaryOperation(Expression* left,Expression* right){
    this->left = left;
    this->right = right;
}

BinaryOperation::~BinaryOperation(){
    delete left;
    delete right;
}


