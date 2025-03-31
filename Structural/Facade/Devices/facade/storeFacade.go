package facade

import (
	"Devices/commands"
	"Devices/devices"
	"Devices/inventories"
	"Devices/users"
)

type StoreFacade struct {
	items inventories.InventoryRepository
}

func NewStoreFacade() *StoreFacade {
	return &StoreFacade{items: inventories.GetInstance()}
}

func (this *StoreFacade) BuyDevice(product devices.Device) error {
	command := commands.NewBuyCommand(product, this.items)
	err := command.Execute()
	if err != nil {
		return err
	}
	return nil
}

func (this *StoreFacade) SellDevice(user *users.User, product devices.Device) error {
	command := commands.NewSellCommand(product, this.items, user)
	err := command.Execute()
	if err != nil {
		return err
	}
	return nil
}
