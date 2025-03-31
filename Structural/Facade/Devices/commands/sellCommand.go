package commands

import (
	"Devices/devices"
	"Devices/inventories"
	"Devices/users"
)

type SellCommand struct {
	product devices.Device
	items   inventories.InventoryRepository
	user    *users.User
}

func NewSellCommand(product devices.Device, items inventories.InventoryRepository, user *users.User) *SellCommand {
	return &SellCommand{product: product, items: items, user: user}
}

func (this *SellCommand) Execute() error {
	err := this.items.RemoveFromInventory(this.product)
	if err != nil {
		return err
	}
	this.user.AddToCard(this.product)
	return nil
}
