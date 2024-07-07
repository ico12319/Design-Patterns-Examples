#include "Variable.h"


class UnaryExpression : public Expression{
    
protected:
    Expression* expr;
    
public:
    UnaryExpression(Expression* expr);
    ~UnaryExpression();
    
};
