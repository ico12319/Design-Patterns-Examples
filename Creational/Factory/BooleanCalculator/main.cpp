#include "Parser.h"


int main(int argc, const char * argv[]) {
    BooleanInterpretation boolean;
    boolean.setValue('p', true);
    boolean.setValue('q', false);
    boolean.setValue('c', true);
    
    Expression* expr = new Conjunction(new Negation(new Variable('q')),new Variable('p'));
    std::cout<<expr->eval(boolean)<<std::endl;
    
    std::string_view str = "(((p&q)&(r|t))|(!q))";
    
    try{
        Expression* toParse = parser(str);
        std::cout<<toParse->eval(boolean)<<std::endl;
    }
    catch(const std::logic_error& e){
        std::cout<<e.what()<<std::endl;
    }
}
