#pragma once
#include "Pair.h"
#include <iostream>

class Function{
protected:
    int32_t* points;
    size_t count;
    
    void copy(const Function& other);
    void move(Function&& other);
    void destroy();
    
public:
    Function() = default;
    Function(const int32_t* points,size_t count);
    Function(const Function& other);
    Function(Function&& other);
    Function& operator=(const Function& other);
    Function& operator=(Function&& other);
    virtual ~Function();
    virtual Pair operator()(int32_t point) const = 0;
    virtual bool isPointExcluded(int32_t point) const  = 0;
};
