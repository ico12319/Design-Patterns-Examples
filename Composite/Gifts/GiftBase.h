#pragma once
#include <iostream>

class GiftBase{
protected:
    std::string name;
    double price;
public:
    GiftBase();
    GiftBase(const std::string& name,double price);
    virtual ~GiftBase() = default;
    virtual GiftBase* clone() const = 0;
    virtual double calculatePrice() const = 0;
};
