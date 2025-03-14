#include "factory.h"
#include "constants.h"

int main() {
     try{
        auto collection = run(FILE_NAMES::FILE_NAME1,FILE_NAMES::FILE_NAME2);
        std::cout<<collection->contains(1)<<std::endl;
        delete collection;
    }
    catch(...){
        std::cout<<"Error!"<<std::endl;
    }
    
}
