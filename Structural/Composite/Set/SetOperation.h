#pragma once
#include "Set.h"

class SetOperation : public Set{
    
protected:
    Set** sets;
    size_t count;
    size_t capacity;
    
    void copy(const SetOperation& other);
    void move(SetOperation&& other);
    void destroy();
    void resize(size_t newCap);
    
public:
    SetOperation();
    SetOperation(Set** sets,size_t count);
    SetOperation(const SetOperation& other);
    SetOperation(SetOperation&& other);
    SetOperation& operator=(const SetOperation& other);
    SetOperation& operator=(SetOperation&& other);
    virtual ~SetOperation();
    void addSet(Set* set);
    
};
