#include <stdio.h>
#include "Parser.h"


Expression* parser(std::string_view str){
    
    
    if(str.length() == 1)
        return new Variable(str[0]);
    
    str = str.substr(1,str.length() - 2);

    
    
    size_t count = 0;
    
    for(int i = 0;i<str.length();i++){
        if(str[i] == '('){
            count++;
        }
        else if(str[i] == ')'){
            count--;
        }
        else if(count == 0){
            if(str[i] == '&'){
                return new Conjunction(parser(str.substr(0,i)),parser(str.substr(i+1,str.length() - i - 1)));
            }
            else if(str[i] == '|'){
                return new Disjunction(parser(str.substr(0,i)),parser(str.substr(i+1,str.length() - i - 1)));
            }
            else if(str[i] == '!'){
                return new Negation(parser(str.substr(i+1,str.length() - i - 1)));
            }
        }
    }
    throw std::invalid_argument("Invalid expression!");
    
}
