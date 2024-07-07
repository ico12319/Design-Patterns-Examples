#include <iostream>

const int ALPHABET_SIZE = 26;

class BooleanInterpretation{
    
private:
    bool symbolValues[ALPHABET_SIZE];
    
public:
    bool getValue(char symbol) const;
    void setValue(char symbol,bool value);
};
