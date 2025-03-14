#include "GiftPackage.h"
#include "SingleGift.h"

int main(int argc, const char * argv[]) {
   
    GiftBase* gift1 = new SingleGift("Car",12.50);
    GiftBase* gift2 = new SingleGift("Var",100);
    GiftsInterface* package = new GiftsPackage();
    GiftBase* gift4 = new SingleGift("Lego",13.56);
    GiftBase* gift5 = new SingleGift("Star-Wars",10);
    package->add(gift4);
    package->add(gift5);
    
    
    GiftsInterface* gift3 = new GiftsPackage();
    gift3->add(gift1);
    gift3->add(gift2);
    gift3->add(package);
    std::cout<<gift3->calculatePrice()<<std::endl;
    
    
    
    delete gift3;
}
