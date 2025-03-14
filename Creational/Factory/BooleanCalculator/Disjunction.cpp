#include <stdio.h>
#include "Disjunction.h"

Disjunction::Disjunction(Expression* left,Expression* right) : BinaryOperation(left, right){}


bool Disjunction::eval(const BooleanInterpretation& interp) const{
    return left->eval(interp) || right->eval(interp);
}

Expression* Disjunction::clone() const{
    return new Disjunction(left->clone(),right->clone());
}
