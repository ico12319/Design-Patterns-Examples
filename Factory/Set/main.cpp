#include "IntersectionSet.h"

int main(int argc, const char * argv[]) {
    
    //int32_t elements[] = {0,2,4,6};
    //std::ofstream ofs("Excluded.dat",std::ios::binary);
    //ofs.write(reinterpret_cast<const char*>(elements), 4 * sizeof(int32_t));
    
    //int32_t elements[] = {1,4,7,54};
    //std::ofstream ofs("Included.dat",std::ios::binary);
    //ofs.write(reinterpret_cast<const char*>(elements), 4 * sizeof(int32_t));
    
    
    
    //Set* set1 = craftEvenSet();
    
    
    std::ifstream ifs1("Excluded.dat",std::ios::binary);
    std::ifstream ifs2("Included.dat",std::ios::binary);
    
    Set* set = craftIntersectionSet(ifs1, ifs2);
    std::cout<<"{ ";
    for(int i = 0;i<55;i++){
        if(set->isContained(i))
            std::cout<<i<<" ";
    }
    std::cout<<"}"<<std::endl;
    
    delete set;
}
