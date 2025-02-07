#include "directory.h"
#include "file.h"

int main() {
    
    file_entity* file1 = new file(12);
    file_entity* file2 = new file(1);
    file_entity* file3 = new file(9);
    file_entity* file4 = new file(8);
    file_entity* file5 = new file(1);
    
    file_container* directory = new class directory();
    directory->push_file(file1);
    directory->push_file(file2);
    
    
    file_container* directory2 = new class directory();
    directory2->push_file(directory);
    directory2->push_file(file3);
    directory2->push_file(file4);
    directory2->push_file(file5);
    
    
    std::cout<<directory2->size()<<std::endl;
    
    delete directory2;
    
}
