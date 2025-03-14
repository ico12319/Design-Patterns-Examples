#pragma once
#include "Function.h"


class Type1 : public Function{
    
public:
    Type1() = default;
    Type1(const int32_t* points,size_t count);
    virtual bool isPointExcluded(int32_t point) const override;
    virtual Pair operator()(int32_t point) const override;
    
};
