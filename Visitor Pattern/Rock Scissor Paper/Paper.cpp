#include "Paper.h"


Output Paper::beats(const Type* other) const{
    return other->beatsPaper(this);
}

Output Paper::beatsRock(const Rock* other) const{
    return Output::LOSS;
}

Output Paper::beatsPaper(const Paper* other) const{
    return Output::DRAW;
}

Output Paper::beatsScissor(const Scissor* other) const{
    return Output::WIN;
}

Type* Paper::clone() const{
    return new Paper(*this);
}


void Paper::print() const{
    std::cout<<"The winner is Paper!"<<std::endl;
}
