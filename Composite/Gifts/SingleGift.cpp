#include <stdio.h>
#include "SingleGift.h"

SingleGift::SingleGift(const std::string& name,double price) : GiftBase(name, price){}

double SingleGift::calculatePrice() const{
    return price;
}

GiftBase* SingleGift::clone() const{
    return new SingleGift(*this);
}

