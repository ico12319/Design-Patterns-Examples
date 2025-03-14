#pragma once
#include "Function.h"

class Type0 : public Function{
    
private:
    int32_t* results;
    
    void copy(const Type0& other);
    void move(Type0&& other);
    void destroy();
    
public:
    Type0() = default;
    Type0(const int32_t* points,size_t count,const int32_t* results);
    Type0(const Type0& other);
    Type0(Type0&& other);
    Type0& operator=(const Type0& other);
    Type0& operator=(Type0&& other);
    ~Type0();
    
    virtual bool isPointExcluded(int32_t point) const override;
    virtual Pair operator()(int32_t point) const override;
};
