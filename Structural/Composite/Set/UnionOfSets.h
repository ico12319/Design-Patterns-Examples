#pragma once
#include "SetOperation.h"


class UnionOfSets : public SetOperation{
    
public:
    UnionOfSets();
    UnionOfSets(Set** sets,size_t count);
    virtual bool isContained(int32_t element) const override;
    virtual Set* clone() const override;
};
