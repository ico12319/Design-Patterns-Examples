#pragma once
#include "Elements.h"

class ExcludedElements : public Elements{
    
public:
    ExcludedElements() = default;
    ExcludedElements(const int32_t* elements,size_t size);
    virtual bool operator()(int32_t element) const override;
};
