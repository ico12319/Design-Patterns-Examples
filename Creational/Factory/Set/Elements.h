#pragma once
#include <iostream>


class Elements{
protected:
    int32_t* elements;
    size_t size;
    
    void copy(const Elements& other);
    void move(Elements&& other);
    void destroy();
    
public:
    Elements() = default;
    Elements(const int32_t* elements,size_t size);
    Elements(const Elements& other);
    Elements(Elements&& other);
    Elements& operator=(const Elements& other);
    Elements& operator=(Elements&& other);
    virtual ~Elements();
    virtual bool operator()(int32_t element) const  = 0;
};
