#include <stdio.h>
#include "MathCalculator.h"


MathCalculator::MathCalculator(std::string_view str){
    this->expr = calculator(str);
}

void MathCalculator::destroy(){
    delete expr;
}

void MathCalculator::copy(const MathCalculator& other){
    this->expr = other.expr->clone();
}

void MathCalculator::move(MathCalculator&& other){
    this->expr = other.expr;
    other.expr = nullptr;
}

MathCalculator::MathCalculator(const MathCalculator& other){
    copy(other);
}

MathCalculator::MathCalculator(MathCalculator&& other){
    move(std::move(other));
}

MathCalculator::~MathCalculator(){
    destroy();
}

MathCalculator& MathCalculator::operator=(const MathCalculator& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

MathCalculator& MathCalculator::operator=(MathCalculator&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}


double MathCalculator::evaluate() const{
    return expr->eval();
}

