#include "directory.h"

size_t directory::size() const{
    size_t total_size = 0;
    for(const auto& file : files)
        total_size += file->size();
    return total_size;
}

file_entity* directory::clone() const{
    return new directory(*this);
}
