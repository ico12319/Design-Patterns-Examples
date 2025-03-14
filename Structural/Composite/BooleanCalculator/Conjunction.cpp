#include <stdio.h>
#include "Conjunction.h"

Conjunction::Conjunction(Expression* left,Expression* right) : BinaryOperation(left, right){}

bool Conjunction::eval(const BooleanInterpretation& interp) const{
    return left->eval(interp) && right->eval(interp);
 }

Expression* Conjunction::clone() const{
    return new Conjunction(left->clone(),right->clone());
}
