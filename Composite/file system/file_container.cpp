#include "file_container.h"

void file_container::push_file(file_entity* file){
    if(!file)
        throw std::invalid_argument("Invalid file format");
    files.push_back(file);
}


file_container::~file_container(){
    for(auto& file : files)
        delete file;
}
