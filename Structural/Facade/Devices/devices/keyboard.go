package devices

import "fmt"

type Keyboard struct {
	model  string
	price  float64
	layout string
}

func NewKeyboard(model string, price float64, layout string) *Keyboard {
	return &Keyboard{model: model, price: price, layout: layout}
}

func (this *Keyboard) GetModel() string {
	return this.model
}

func (this *Keyboard) GetPrice() float64 {
	return this.price
}

func (this *Keyboard) GetDescription() string {
	return fmt.Sprintf("Keyboard - Model %s, Price %.2f has %d layout.", this.model, this.price, this.layout)
}
