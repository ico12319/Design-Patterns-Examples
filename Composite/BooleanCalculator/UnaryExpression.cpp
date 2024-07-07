#include <stdio.h>
#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(Expression* other){
    this->expr = other;
}

UnaryExpression::~UnaryExpression(){
    delete expr;
}
