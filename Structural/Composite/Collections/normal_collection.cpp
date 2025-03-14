#include "normal_collection.h"

normal_collection::normal_collection() : collection(){}

normal_collection::normal_collection(const std::vector<int>& container) : collection(container){}

bool normal_collection::contains(int arg) const{
    auto it = std::find(this->container.begin(), this->container.end(),arg);
    return it != this->container.end();
}

collection* normal_collection::clone() const{
    return new normal_collection(*this);
}


