#pragma once
#include "file_entity.h"

class file : public file_entity{
private:
    size_t file_size = 0;
    
public:
    file(size_t size);
    virtual size_t size() const override;
    virtual file_entity* clone() const override;
};



