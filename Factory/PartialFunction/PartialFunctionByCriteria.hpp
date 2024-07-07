#pragma once
#include "PartialFunction.h"


template<class Function>
class PartialFunctionByCriteria : public PartialFunction{
    
private:
    Function func;

public:
    PartialFunctionByCriteria() = default;
    PartialFunctionByCriteria(const Function& func);
    virtual bool isDefined(int32_t point) const override;
    virtual int32_t operator()(int32_t point) const override;
    virtual PartialFunction* clone() const override;
    
};


template<class Function>
PartialFunctionByCriteria<Function>::PartialFunctionByCriteria(const Function& func){
    this->func = func;
}


template<class Function>
bool PartialFunctionByCriteria<Function>::isDefined(int32_t point) const{
    return !func.isPointExcluded(point);
}

template<class Function>
int32_t PartialFunctionByCriteria<Function>::operator()(int32_t point) const{
    return func(point).getValue();
}

template<class Function>
PartialFunction* PartialFunctionByCriteria<Function>::clone() const{
    return new PartialFunctionByCriteria(*this);
}
