#include "collection_intersection.h"

collection_intersection::collection_intersection(collection* left,collection* right) : collection_operation(left, right){}

bool collection_intersection::contains(int arg) const{
    return this->left->contains(arg) && this->right->contains(arg);
}

collection* collection_intersection::clone() const{
    return new collection_intersection(*this);
}
