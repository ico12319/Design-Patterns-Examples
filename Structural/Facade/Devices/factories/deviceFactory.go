package factories

import (
	"Devices/devices"
	"fmt"
)

func CraftDevice(deviceType string, model string, price float64, exp interface{}) (devices.Device, error) {
	if deviceType == "pc" {
		return devices.NewPc(model, price), nil
	} else if deviceType == "laptop" {
		weight, ok := exp.(int)
		if !ok {
			return nil, fmt.Errorf("invalid interfce type")
		}
		return devices.NewLaptop(model, price, weight), nil
	} else if deviceType == "mouse" {
		dpi, ok := exp.(int)
		if !ok {
			return nil, fmt.Errorf("invalid interface type")
		}
		return devices.NewMouse(model, price, dpi), nil
	} else if deviceType == "keyboard" {
		layout, ok := exp.(string)
		if !ok {
			return nil, fmt.Errorf("invalid interface type")
		}
		return devices.NewKeyboard(model, price, layout), nil
	}
	return nil, fmt.Errorf("invalid device type %s", deviceType)
}
