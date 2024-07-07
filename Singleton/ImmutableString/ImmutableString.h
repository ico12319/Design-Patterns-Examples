#include "StringPool.h"


class ImmutableString{
    
private:
    const char* data;
    size_t len;
    
    void copy(const ImmutableString& other);
    void destroy();
    static StringPool pool;
    
public:
    const char* c_str() const;
    ImmutableString(const char* data);
    ImmutableString(const ImmutableString& other);
    ImmutableString& operator=(const ImmutableString& other) = delete;
    ~ImmutableString();
    size_t length() const;
    
};
