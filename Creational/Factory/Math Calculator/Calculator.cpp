#include <stdio.h>
#include "Calculator.h"
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Division.h"
#include "Multiplier.h"


Expression* calculator(std::string_view str){
    str = str.substr(1,str.length() - 2);
    
    
    bool isNumber = true;
    for(int i = 0;i<str.length();i++){
        if(!isdigit(str[i]))
            isNumber = false;
    }
    
    if(isNumber)
        return new Number(std::stoi(std::string(str)));;
    
    size_t count = 0;
    for(int i = 0;i<str.length();i++){
        if(str[i] == '(')
            count++;
        else if(str[i] == ')')
            count--;
        else if(count == 0){
            if(str[i] == '+'){
                return new Plus(calculator(str.substr(0,i)),calculator(str.substr(i+1,str.length() - i - 1)));
            }
            else if(str[i] == '-'){
                return new Minus(calculator(str.substr(0,i)),calculator(str.substr(i+1,str.length() - i - 1)));
            }
            else if(str[i] == '*'){
                return new Multiplier(calculator(str.substr(0,i)),calculator(str.substr(i+1,str.length() - i - 1)));
            }
            else if(str[i] == '/'){
                return new Division(calculator(str.substr(0,i)),calculator(str.substr(i+1,str.length() - i - 1)));
            }
        }
    }
    throw std::invalid_argument("Invalid expression!");
    
}
