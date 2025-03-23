#include "computer.hpp"


int main(int argc, const char * argv[]) {
    computer* pc1 = computer::builder(250, 32)->set_bluetooth_enabled(1)->set_graphics_card_enabled(1)->build();
    
    computer* pc2 = computer::builder(350, 16)->build();
    
    std::cout<<pc1->get_ram()<<std::endl;
    std::cout<<pc2->get_ram()<<std::endl;
    std::cout<<pc1->get_is_bluetooth_enabled()<<std::endl;
    std::cout<<pc2->get_is_bluetooth_enabled()<<std::endl;
    
    delete pc1;
    delete pc2;
}
