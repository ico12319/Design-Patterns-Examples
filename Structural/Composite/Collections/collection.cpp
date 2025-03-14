#include "collection.h"

collection::collection(const std::vector<int>& container){
    this->container.resize(container.size());
    for(int i = 0;i<container.size();i++)
        this->container[i] = container[i];
}
