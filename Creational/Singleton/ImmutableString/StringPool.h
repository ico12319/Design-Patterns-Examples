#include <iostream>


class StringPool{
    
private:
    
    struct StringRecords{
        char* str;
        size_t refCount;
    };
    StringRecords* records;
    size_t stringCount;
    size_t capacity;
    
    void resize(size_t newCap);
    void removeRecord(size_t index);
    int findAllocatedString(const char* data) const;
    size_t allocateNewString(const char* data);
    
public:
    StringPool();
    ~StringPool();
    const char* getAllocatedString(const char* data);
    void releaseString(const char* str);
};
