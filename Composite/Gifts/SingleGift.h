#pragma once
#include "GiftBase.h"

class SingleGift : public GiftBase{
    
public:
    SingleGift(const std::string& name,double price);
    virtual double calculatePrice() const override;
    virtual GiftBase* clone() const override;
};
