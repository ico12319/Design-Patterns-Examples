#pragma once
#include "Function.h"

class Type2 : public Function{
public:
    Type2() = default;
    Type2(const int32_t* points,size_t count);
    virtual bool isPointExcluded(int32_t point) const override;
    virtual Pair operator()(int32_t point) const override;
};
