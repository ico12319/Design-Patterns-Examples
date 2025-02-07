#include "file.h"

file::file(size_t size) : fail_size(size){}

size_t file::size() const{
    return fail_size;
}

file_entity* file::clone() const{
    return new file(*this);
}
