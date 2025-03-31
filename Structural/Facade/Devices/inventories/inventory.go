package inventories

import (
	"Devices/devices"
	"fmt"
	"sync"
)

type Inventory struct {
	products map[devices.Device]int
	mutex    sync.Mutex
}

var instance *Inventory
var once sync.Once

func GetInstance() *Inventory {
	once.Do(func() {
		instance = &Inventory{products: make(map[devices.Device]int)}
	})
	return instance
}

func (this *Inventory) AddToInventory(product devices.Device) error {
	this.mutex.Lock()
	defer this.mutex.Unlock()

	if product == nil {
		return fmt.Errorf("the provided device is invalid")
	}
	this.products[product]++
	return nil
}

func (this *Inventory) RemoveFromInventory(product devices.Device) error {
	this.mutex.Lock()
	defer this.mutex.Unlock()

	if product == nil {
		return fmt.Errorf("the provided device is invalid ")
	}
	_, isContained := this.products[product]
	if !isContained {
		return fmt.Errorf("the product you want to remove is not contained in the inventory")
	}
	delete(this.products, product)
	return nil
}

func (this *Inventory) ContainsDevice(product devices.Device) bool {
	this.mutex.Lock()
	defer this.mutex.Unlock()

	_, isContained := this.products[product]
	return isContained
}
