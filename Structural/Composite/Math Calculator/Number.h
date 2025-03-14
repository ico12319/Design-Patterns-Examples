#pragma once
#include "Expression.h"


class Number : public Expression{
    
    
private:
    double num;
    
public:
    Number(double num);
    virtual Expression* clone() const override;
    virtual double eval() const override;
    
    
};
