#include "BooleanInterpretation.h"


class Expression{
    
public:
    Expression() = default;
    Expression(const Expression& other) = delete;
    Expression& operator=(const Expression& other) = delete;
    virtual bool eval(const BooleanInterpretation& other) const = 0;
    virtual ~Expression() = default;
    virtual Expression* clone() const = 0;
};
