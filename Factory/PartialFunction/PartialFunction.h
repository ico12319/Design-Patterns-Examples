#pragma once
#include <iostream>

class PartialFunction{
    
public:
    PartialFunction() = default;
    virtual bool isDefined(int32_t point) const = 0;
    virtual int32_t operator()(int32_t point) const = 0;
    virtual ~PartialFunction() = default;
    virtual PartialFunction* clone() const = 0;
};
