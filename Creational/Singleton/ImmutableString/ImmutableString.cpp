#include <stdio.h>
#include "ImmutableString.h"


StringPool ImmutableString::pool;

ImmutableString::ImmutableString(const ImmutableString& other){
    copy(other);
}

ImmutableString::ImmutableString(const char* data){
    data = pool.getAllocatedString(data);
    len = std::strlen(data);
}

void ImmutableString::destroy(){
    pool.releaseString(data);
    data = nullptr;
}

ImmutableString::~ImmutableString(){
    destroy();
}

size_t ImmutableString::length() const{
    return len;
}


const char* ImmutableString::c_str() const{
    return data;
}

void ImmutableString::copy(const ImmutableString& other){
    data = pool.getAllocatedString(other.data);
    len = other.len;
}





