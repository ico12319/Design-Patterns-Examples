#include <stdio.h>
#include "Plus.h"


Plus::Plus(Expression* left,Expression* right) : BinaryExpression(left, right){}

double Plus::eval() const{
    return left->eval() + right->eval();
}

Expression* Plus::clone() const{
    return new Plus(left->clone(),right->clone());
}
