package devices

import "fmt"

type PC struct {
	model string
	price float64
}

func NewPc(model string, price float64) *PC {
	return &PC{model: model, price: price}
}

func (this *PC) GetModel() string {
	return this.model
}

func (this *PC) GetPrice() float64 {
	return this.price
}

func (this *PC) GetDescription() string {
	return fmt.Sprintf("Desktop - Model: %s, Price: %.2f", this.model, this.price)
}
