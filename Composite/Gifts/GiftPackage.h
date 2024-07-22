#pragma once
#include "GiftsInterface.h"

class GiftsPackage : public GiftsInterface{
    
public:
    GiftsPackage();
    GiftsPackage(const GiftBase** gifts,size_t size);
    virtual double calculatePrice() const override;
    virtual GiftBase* clone() const override;
};
