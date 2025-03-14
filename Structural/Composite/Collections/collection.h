#pragma once
#include <iostream>
#include <fstream>

class collection{
protected:
    std::vector<int> container;
    
public:
    collection() = default;
    collection(const std::vector<int>& container);
    virtual bool contains(int arg) const = 0;
    virtual collection* clone() const = 0;
    virtual ~collection() = default;
};
