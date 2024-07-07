#pragma once
#include "PartialFunction.h"

class MaximumOrMinimum : public PartialFunction{
    
protected:
    PartialFunction** functions;
    size_t count;
    size_t capacity;
    
    void copy(const MaximumOrMinimum& other);
    void move(MaximumOrMinimum&& other);
    void destroy();
    void resize(size_t newCap);
    
public:
    MaximumOrMinimum();
    MaximumOrMinimum(PartialFunction** functions,size_t count);
    MaximumOrMinimum(const MaximumOrMinimum& other);
    MaximumOrMinimum(MaximumOrMinimum&& other);
    virtual ~MaximumOrMinimum();
    MaximumOrMinimum& operator=(const MaximumOrMinimum& other);
    MaximumOrMinimum& operator=(MaximumOrMinimum&& other);
    void add(PartialFunction* fucntion);
    virtual bool isDefined(int32_t point) const override;
};
