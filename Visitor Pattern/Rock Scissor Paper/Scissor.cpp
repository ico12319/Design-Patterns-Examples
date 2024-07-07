#include <stdio.h>
#include "Scissor.h"


Output Scissor::beats(const Type* other) const{
    return other->beatsScissor(this);
}

Output Scissor::beatsRock(const Rock* other) const{
    return Output::WIN;
}

Output Scissor::beatsPaper(const Paper* other) const{
    return Output::LOSS;
}

Output Scissor::beatsScissor(const Scissor* other) const{
    return Output::DRAW;
}

Type* Scissor::clone() const{
    return new Scissor(*this);
}

void Scissor::print() const{
    std::cout<<"The winner is Scissor!"<<std::endl;
}
