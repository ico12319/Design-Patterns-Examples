#pragma once
#include <iostream>

class Set{
    
    
public:
    virtual ~Set() = default;
    virtual bool isContained(int32_t element) const = 0;
    virtual Set* clone() const = 0;
    
};
