#pragma once
#include <iostream>

class computer{
private:
    size_t sdd = 0;
    size_t ram = 0;
    //optional parameters
    bool is_graphics_card_enabled = false;
    bool is_bluetooth_enabled = false;
    friend class computer_builder;
    
    class computer_builder{
    private:
        size_t sdd = 0;
        size_t ram = 0;
        //optional pamaters
        bool is_graphics_card_enabled = false;
        bool is_bluetooth_enabled = false;
        friend class computer;
        
        computer_builder(size_t sdd,size_t ram){
            this->sdd = sdd;
            this->ram = ram;
        }
        
    public:
        // here we are returning an instance of the builder class so we can chain the setters!
        // we are building the object step by step
        computer_builder* set_bluetooth_enabled(bool is_bluetooth_enabled){
            this->is_bluetooth_enabled = is_bluetooth_enabled;
            return this;
        }
        
        computer_builder* set_graphics_card_enabled(bool is_graphics_card_enabled){
            this->is_graphics_card_enabled = is_graphics_card_enabled;
            return this;
        }
        
        computer* build(){
            return new computer(*this);
        }
    };
    
public:
    computer(const computer_builder& builder){
        this->sdd = builder.sdd;
        this->ram = builder.ram;
        this->is_bluetooth_enabled = builder.is_bluetooth_enabled;
        this->is_graphics_card_enabled = builder.is_graphics_card_enabled;
    }
    
    static computer_builder* builder(size_t sdd,size_t ram){
        return new computer_builder(sdd, ram);
    }
    
    const size_t get_sdd() const{
        return this->sdd;
    }
    const size_t get_ram() const{
        return this->ram;
    }
    
    const bool get_is_bluetooth_enabled() const{
        return this->is_bluetooth_enabled;
    }
    
    const bool get_is_graphics_card_enabled() const{
        return this->is_graphics_card_enabled;
    }
};
