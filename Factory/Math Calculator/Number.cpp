#include <stdio.h>
#include "Number.h"


Number::Number(double num){
    this->num = num;
}

Expression* Number::clone() const{
    return new Number(num);
}

double Number::eval() const{
    return num;
}
