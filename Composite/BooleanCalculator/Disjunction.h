#include "Conjunction.h"


class Disjunction : public BinaryOperation{
    
    
public:
    Disjunction(Expression* left,Expression* right);
    virtual bool eval(const BooleanInterpretation& interp) const override;
    virtual Expression* clone() const override;
    
    
};
