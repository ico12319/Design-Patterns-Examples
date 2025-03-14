#include "UnaryExpression.h"

class Negation : public UnaryExpression{
    
public:
    Negation(Expression* expr);
    virtual bool eval(const BooleanInterpretation& other) const override;
    virtual Expression* clone() const override;
    
};
