package main

import (
	facade2 "Devices/facade"
	"Devices/factories"
	"Devices/users"
)

//TIP <p>To run your code, right-click the code and select <b>Run</b>.</p> <p>Alternatively, click
// the <icon src="AllIcons.Actions.Execute"/> icon in the gutter and select the <b>Run</b> menu item from here.</p>

func main() {

	device1, _ := factories.CraftDevice("laptop", "macbook", 2450.50, 1000)
	device2, _ := factories.CraftDevice("mouse", "cougar", 150, 400)

	user1 := users.NewUser("ivan")

	facade := facade2.NewStoreFacade()
	err := facade.BuyDevice(device1)
	if err != nil {
		panic(err)
	}
	err = facade.BuyDevice(device2)
	err = facade.SellDevice(user1, device1)
	err = facade.SellDevice(user1, device2)
	
	user1.GetCartInfo()

}
