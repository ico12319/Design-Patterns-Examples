#include <stdio.h>
#include "GiftBase.h"

GiftBase::GiftBase(){
    this->name = "Unknown gift";
    this->price = 0;
}

GiftBase::GiftBase(const std::string& name,double price){
    this->name = name;
    this->price = price;
}


