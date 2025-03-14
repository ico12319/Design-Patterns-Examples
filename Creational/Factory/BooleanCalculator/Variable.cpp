#include "Variable.h"

Variable::Variable(char symbol){
    this->symbol = symbol;
}

bool Variable::eval(const BooleanInterpretation& interp) const{
    return interp.getValue(symbol);
}

Expression* Variable::clone() const{
    return new Variable(symbol);
}
