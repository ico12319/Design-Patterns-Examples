#pragma once
#include "MaximumOrMinimum.h"

class MaximumPartialFunction : public MaximumOrMinimum{
    
public:
    MaximumPartialFunction();
    MaximumPartialFunction(PartialFunction** functions,size_t count);
    virtual int32_t operator()(int32_t point) const override;
    virtual PartialFunction* clone() const override;
};
