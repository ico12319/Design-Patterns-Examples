#pragma once
#include "Set.h"

template<class T>

class SetByCriteria : public Set{
    
private:
    T pred;
    
public:
    SetByCriteria(const T& pred);
    virtual bool isContained(int32_t element) const override;
    virtual Set* clone() const override;
};


template<class T>
SetByCriteria<T>::SetByCriteria(const T& pred){
    this->pred = pred;
}

template<class T>
bool SetByCriteria<T>::isContained(int32_t element) const{
    return pred(element);
}

template<class T>
Set* SetByCriteria<T>::clone() const{
    return new SetByCriteria(*this);
}

