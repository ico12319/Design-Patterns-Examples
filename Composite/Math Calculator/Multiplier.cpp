#include <stdio.h>
#include "Multiplier.h"


Multiplier::Multiplier(Expression* left,Expression* right) : BinaryExpression(left, right){}

double Multiplier::eval() const{
    return left->eval() * right->eval();
}

Expression* Multiplier::clone() const{
    return new Multiplier(left->clone(),right->clone());
}
