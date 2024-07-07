#include <stdio.h>
#include "Crafter.h"
#include "Type0.h"
#include "Type1.h"
#include "Type2.h"
#include "PartialFunctionByCriteria.hpp"
#include "MaximumPartialFunction.h"
#include "MinimumPartialFunction.h"


PartialFunction* crafter(std::ifstream& ifs){
    
    int16_t N;
    int16_t T;
    ifs.read(reinterpret_cast<char*>(&N), sizeof(int16_t));
    ifs.read(reinterpret_cast<char*>(&T),sizeof(int16_t));
    
    if(T == 0){
        int32_t* points = new int32_t[N];
        ifs.read(reinterpret_cast<char*>(points), N * sizeof(int32_t));
        int32_t* results = new int32_t[N];
        ifs.read(reinterpret_cast<char*>(results),N * sizeof(int32_t));
        Type0 func(points,N,results);
        PartialFunction* toReturn = new PartialFunctionByCriteria<Type0>(func);
        delete[]points;
        delete[]results;
        return toReturn;
    }
    else if(T == 1){
        int32_t* points = new int32_t[N];
        ifs.read(reinterpret_cast<char*>(points),N * sizeof(int32_t));
        Type1 func(points, N);
        PartialFunction* toReturn = new PartialFunctionByCriteria<Type1>(func);
        delete[]points;
        return toReturn;
    }
    else if(T == 2){
        int32_t* points = new int32_t[N];
        ifs.read(reinterpret_cast<char*>(points), N * sizeof(int32_t));
        Type2 func(points, N);
        PartialFunction* toReturn = new PartialFunctionByCriteria<Type2>(func);
        delete[]points;
        return toReturn;
    }
    else if(T == 3){
        MaximumOrMinimum* toReturn = new MaximumPartialFunction();
        for(int i = 0;i<N;i++){
            char fileName[1024];
            ifs.getline(fileName, 1024,'\0');
            std::ifstream subIfs(fileName,std::ios::binary);
            PartialFunction* toAdd = crafter(subIfs);
            if(toAdd != nullptr){
                toReturn->add(toAdd);
            }
        }
        return toReturn;
    }
    else if(T == 4){
        MaximumOrMinimum* toReturn = new MinimumPartialFunction();
        for(int i = 0;i<N;i++){
            char fileName[1024];
            ifs.getline(fileName, 1024,'\0');
            std::ifstream subIfs(fileName,std::ios::binary);
            PartialFunction* toAdd = crafter(subIfs);
            if(toAdd != nullptr){
                toReturn->add(toAdd);
            }
        }
        return toReturn;
    }
    
    throw std::invalid_argument("Unable to access the provided binary file");
    
}
