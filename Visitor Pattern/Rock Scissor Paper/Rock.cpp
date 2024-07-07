#include "Rock.h"

Output Rock::beats(const Type* other) const{
    return other->beatsRock(this);
}


Output Rock::beatsRock(const Rock* other) const{
    return Output::DRAW;
}

Output Rock::beatsPaper(const Paper* other) const{
    return Output::WIN;
}

Output Rock::beatsScissor(const Scissor* other)const{
    return Output::LOSS;
}


Type* Rock::clone() const{
    return new Rock(*this);
}


void Rock::print() const{
    std::cout<<"The winner is Rock!"<<std::endl;
}
