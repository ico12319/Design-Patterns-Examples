#pragma once
#include "collection.h"

class normal_collection : public collection{
public:
    normal_collection();
    normal_collection(const std::vector<int>& container);
    virtual bool contains(int arg) const override;
    virtual collection* clone() const override;
};



