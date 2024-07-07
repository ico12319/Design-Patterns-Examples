#include "Negation.h"


class BinaryOperation : public Expression{
    
protected:
    Expression* left;
    Expression* right;
    
public:
    BinaryOperation(Expression* left,Expression* right);
    ~BinaryOperation();
    
};
