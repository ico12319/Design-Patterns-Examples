#pragma once
#include "BinaryExpression.h"


class Division : public BinaryExpression{
    
    
public:
    Division(Expression* left,Expression* right);
    virtual double eval() const override;
    virtual Expression* clone() const override;
    
};
