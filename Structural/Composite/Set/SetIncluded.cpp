#include <stdio.h>
#include "SetIncluded.h"
#include "SetByCriteria.hpp"
#include "IncludedElements.h"


static size_t getFileSize(std::ifstream& ifs){
    size_t curr = ifs.tellg();
    ifs.seekg(curr,std::ios::end);
    size_t fileSize = ifs.tellg();
    ifs.seekg(curr);
    return fileSize;
}

Set* craftSetWithIncluedValues(std::ifstream& ifs){
    size_t fileSize = getFileSize(ifs);
    size_t elementsCount = fileSize / sizeof(int32_t);
    int32_t* elements = new int32_t[elementsCount];
    ifs.read(reinterpret_cast<char*>(elements), elementsCount * sizeof(int32_t));
    IncludedElements included(elements,elementsCount);
    Set* toReturn = new SetByCriteria<IncludedElements>(included);
    delete[]elements;
    return toReturn;
}
