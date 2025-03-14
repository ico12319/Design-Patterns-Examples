#pragma once
#include "BinaryExpression.h"


class Plus : public BinaryExpression{
    
public:
    Plus(Expression* left,Expression* right);
    virtual double eval() const override;
    virtual Expression* clone() const override;
    
};
