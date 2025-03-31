package users

import (
	"Devices/devices"
	"fmt"
)

type User struct {
	name      string
	inventory []devices.Device
}

func NewUser(name string) *User {
	return &User{name: name, inventory: make([]devices.Device, 0, 8)}
}

func (this *User) AddToCard(product devices.Device) {
	if product == nil {
		return
	}
	this.inventory = append(this.inventory, product)
}

func (this *User) GetProductsInCartCount() int {
	return len(this.inventory)
}

func (this *User) GetCartInfo() {
	fmt.Printf("Here is a review of your Shopping Cart %s\n", this.name)
	for i := 0; i < len(this.inventory); i++ {
		fmt.Println(this.inventory[i].GetDescription())
	}
}
