#pragma once
#include "Calculator.h"


class MathCalculator{
    
private:
    Expression* expr;
    
    void copy(const MathCalculator& other);
    void move(MathCalculator&& other);
    void destroy();
    
public:
    MathCalculator(std::string_view str);
    MathCalculator(const MathCalculator& other);
    MathCalculator(MathCalculator&& other);
    ~MathCalculator();
    MathCalculator& operator=(const MathCalculator& other);
    MathCalculator& operator=(MathCalculator&& other);
    
    double evaluate() const;
    
    
};
