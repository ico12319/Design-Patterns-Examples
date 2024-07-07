#include "BinaryOperation.h"

class Conjunction : public BinaryOperation{
    
    
public:
    Conjunction(Expression* left,Expression* right);
    virtual bool eval(const BooleanInterpretation& interp) const override;
    virtual Expression* clone() const override;
    
};
