#pragma once
#include <iostream>

class Expression{
    
    
public:
    virtual Expression* clone() const = 0;
    virtual double eval() const = 0;
    virtual ~Expression() = default;
    
};
