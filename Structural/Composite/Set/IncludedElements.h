#include "Elements.h"

class IncludedElements : public Elements{
    
public:
    IncludedElements() = default;
    IncludedElements(const int32_t* elements,size_t size);
    virtual bool operator()(int32_t element) const override;
};
