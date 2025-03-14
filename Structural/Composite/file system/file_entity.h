#pragma once
#include <iostream>

class file_entity{
public:
    virtual ~file_entity() = default;
    virtual size_t size() const = 0;
    virtual file_entity* clone() const = 0;
};
