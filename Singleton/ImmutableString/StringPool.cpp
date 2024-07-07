#include <stdio.h>
#include "StringPool.h"

StringPool::StringPool(){
    this->capacity = 8;
    this->records = new StringRecords[this->capacity];
    this->stringCount = 0;
}

int StringPool::findAllocatedString(const char* data) const{
    for(int i = 0;i<stringCount;i++){
        if(std::strcmp(data, records[i].str) == 0)
            return i;
    }
    return -1;
}

void StringPool::removeRecord(size_t index){
    std::swap(records[index], records[stringCount - 1]);
    delete[] records[stringCount-1].str;
}


size_t StringPool::allocateNewString(const char* data){
    if(stringCount == capacity)
        resize(capacity * 2);
    size_t firstFree = stringCount++;
    records[firstFree].str = new char[std::strlen(data) + 1];
    std::strcpy(records[firstFree].str, data);
    records[firstFree].refCount = 0;
    return firstFree;
}


void StringPool::resize(size_t newCapacity){
    StringRecords* temp = new StringRecords[newCapacity];
    for(int i = 0;i<newCapacity;i++){
        temp[i] = records[i];
    }
    delete[]records;
    records = temp;
    capacity = newCapacity;
}

const char* StringPool::getAllocatedString(const char* data){
    size_t index = findAllocatedString(data);
    if(index != -1){
        records[index].refCount++;
        return records[index].str;
    }
    size_t firstFree = allocateNewString(data);
    records[firstFree].refCount++;
    stringCount++;
    return records[firstFree].str;
}


void StringPool::releaseString(const char* data){
    size_t index = findAllocatedString(data);
    if(records[index].refCount == 0){
        removeRecord(index);
        stringCount--;
    }
    else{
        records[index].refCount--;
    }
}

StringPool::~StringPool(){
    for(int i = 0;i<capacity;i++)
        delete[] records[i].str;
    delete[] records;
}
