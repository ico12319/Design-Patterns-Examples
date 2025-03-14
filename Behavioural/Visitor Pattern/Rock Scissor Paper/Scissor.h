#include "Rock.h"

class Scissor : public Type{
    
public:
    Scissor() = default;
    virtual Output beats(const Type* other) const override;
    virtual Output beatsRock(const Rock* other) const override;
    virtual Output beatsPaper(const Paper* other) const override;
    virtual Output beatsScissor(const Scissor* other) const override;
    virtual Type* clone() const override;
    virtual void print() const override;
    
};
