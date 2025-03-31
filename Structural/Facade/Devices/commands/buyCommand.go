package commands

import (
	"Devices/devices"
	"Devices/inventories"
)

type BuyCommand struct {
	product devices.Device
	items   inventories.InventoryRepository
}

func NewBuyCommand(product devices.Device, items inventories.InventoryRepository) *BuyCommand {
	return &BuyCommand{product: product, items: items}
}

func (this *BuyCommand) Execute() error {
	return this.items.AddToInventory(this.product)
}
