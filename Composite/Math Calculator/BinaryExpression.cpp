#include <stdio.h>
#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression* left,Expression* right) : left(left),right(right){}

BinaryExpression::~BinaryExpression(){
    delete left;
    delete right;
}


