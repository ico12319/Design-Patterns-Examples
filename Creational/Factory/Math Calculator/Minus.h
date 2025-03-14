#pragma once
#include "BinaryExpression.h"


class Minus : public BinaryExpression{
    
    
public:
    Minus(Expression* left,Expression* right);
    virtual double eval() const override;
    virtual Expression* clone() const override;
};
