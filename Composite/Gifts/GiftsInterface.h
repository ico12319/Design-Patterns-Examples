#pragma once
#include "GiftBase.h"

class GiftsInterface : public GiftBase{
protected:
    GiftBase** gifts;
    size_t size;
    size_t capacity;
    
    void copy(const GiftsInterface& other);
    void move(GiftsInterface&& other);
    void destroy();
    void resize(size_t newCap);
    
public:
    GiftsInterface();
    GiftsInterface(const GiftBase** gifts,size_t size);
    GiftsInterface(const GiftsInterface& other);
    GiftsInterface(GiftsInterface&& other);
    GiftsInterface& operator=(const GiftsInterface& other);
    GiftsInterface& operator=(GiftsInterface&& other);
    virtual ~GiftsInterface();
    void add(GiftBase* gift);
    void remove(size_t index);
};
