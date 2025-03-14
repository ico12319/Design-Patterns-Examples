#pragma once
#include "BinaryExpression.h"


class Multiplier : public BinaryExpression{
    
    
public:
    Multiplier(Expression* left,Expression* right);
    virtual double eval() const override;
    virtual Expression* clone() const override;
};
