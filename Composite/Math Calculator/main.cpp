#include <iostream>
#include "MathCalculator.h"

int main(int argc, const char * argv[]) {
    MathCalculator calculator("(((12)+(10))*(10))");
    MathCalculator calculator2("((2)+(1))");
    
    
    std::cout<<calculator.evaluate()<<std::endl;
    
    
    
}
