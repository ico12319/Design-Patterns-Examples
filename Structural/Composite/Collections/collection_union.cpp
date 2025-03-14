#include "collection_union.h"

collection_union::collection_union(collection* left,collection* right) : collection_operation(left,right){}


bool collection_union::contains(int arg) const{
    return this->left->contains(arg) || this->right->contains(arg);
}

collection* collection_union::clone() const{
    return new collection_union(*this);
}

