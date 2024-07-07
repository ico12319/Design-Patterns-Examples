#include <stdio.h>
#include "Minus.h"

Minus::Minus(Expression* left,Expression* right) : BinaryExpression(left, right){}

double Minus::eval() const{
    return left->eval() - right->eval();
}

Expression* Minus::clone() const{
    return new Minus(left->clone(),right->clone());
}
