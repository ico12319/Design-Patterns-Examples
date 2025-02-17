#pragma once
#include "collection.h"

class sorted_collection : public collection{
public:
    sorted_collection();
    sorted_collection(const std::vector<int>& container);
    virtual bool contains(int arg) const override;
    virtual collection* clone() const override;
};


