#include "Expression.h"

class Variable : public Expression{
    
private:
    char symbol;
    
public:
    Variable(char symbol);
    virtual bool eval(const BooleanInterpretation& interp) const override;
    virtual Expression* clone() const override;
    
};
