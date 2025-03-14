#include <stdio.h>
#include "Division.h"


Division::Division(Expression* left,Expression* right) : BinaryExpression(left, right){}

double Division::eval() const{
    return left->eval() / right->eval();
}

Expression* Division::clone() const{
    return new Division(left->clone(),right->clone());
}
