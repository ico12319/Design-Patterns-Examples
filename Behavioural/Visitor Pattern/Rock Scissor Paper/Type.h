#include <iostream>
#include "Outputs.h"

class Rock;
class Scissor;
class Paper;

class Type{
    
public:
    virtual Output beats(const Type* other) const = 0;
    virtual Output beatsRock(const Rock* other) const = 0;
    virtual Output beatsPaper(const Paper* other) const = 0;
    virtual Output beatsScissor(const Scissor* other) const = 0;
    virtual ~Type() = default;
    virtual Type* clone() const = 0;
    virtual void print() const = 0;
    
};
