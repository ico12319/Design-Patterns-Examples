#pragma once
#include "file_entity.h"

class file_container : public file_entity{
protected:
    std::vector<file_entity*> files;
    
public:
    void push_file(file_entity* file);
    virtual ~file_container();
};
