#include "sorted_collection.h"

sorted_collection::sorted_collection() : collection(){}

sorted_collection::sorted_collection(const std::vector<int>& container) : collection(container){}

bool sorted_collection::contains(int arg) const{
    return std::binary_search(this->container.begin(), this->container.end(), arg);
}

collection* sorted_collection::clone() const{
    return new sorted_collection(*this);
}


