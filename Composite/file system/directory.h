#pragma once
#include "file_container.h"

class directory : public file_container{
public:
    directory() = default;
    virtual file_entity* clone() const override;
    virtual size_t size() const override;

};
