#pragma once
#include "collection.h"

class collection_operation : public collection{
protected:
    collection* left;
    collection* right;
    
    void copy(const collection_operation& other);
    void move(collection_operation&& other);
    void destroy();
    
public:
    collection_operation(collection* left,collection* right);
    collection_operation(const collection_operation& other);
    collection_operation& operator=(const collection_operation& other);
    collection_operation(collection_operation&& other);
    collection_operation& operator=(collection_operation&& other);
    virtual ~collection_operation();
};


