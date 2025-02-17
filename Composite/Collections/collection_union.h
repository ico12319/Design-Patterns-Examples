#pragma once
#include "collection_operation.h"

class collection_union : public collection_operation{
public:
    collection_union(collection* left,collection* right);
    virtual bool contains(int arg) const override;
    virtual collection* clone() const override;
};


