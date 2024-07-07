#pragma once
#include "SetOperation.h"

class IntersectionOfSets : public SetOperation{
    
public:
    IntersectionOfSets();
    IntersectionOfSets(Set** sets,size_t count);
    virtual bool isContained(int32_t element) const override;
    virtual Set* clone() const override;
    
};
