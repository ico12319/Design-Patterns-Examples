#include <stdio.h>
#include "GiftPackage.h"

GiftsPackage::GiftsPackage() : GiftsInterface(){}

GiftsPackage::GiftsPackage(const GiftBase** gifts,size_t size) : GiftsInterface(gifts, size){}

double GiftsPackage::calculatePrice() const{
    double sum = 0;
    for(int i = 0;i<size;i++)
        sum += gifts[i]->calculatePrice();
    return sum;
}

GiftBase* GiftsPackage::clone() const{
    return new GiftsPackage(*this);
}
