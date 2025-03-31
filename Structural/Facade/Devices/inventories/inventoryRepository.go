package inventories

import (
	"Devices/devices"
)

type InventoryRepository interface {
	AddToInventory(product devices.Device) error
	RemoveFromInventory(product devices.Device) error
	ContainsDevice(product devices.Device) bool
}
