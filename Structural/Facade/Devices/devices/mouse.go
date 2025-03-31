package devices

import "fmt"

type Mouse struct {
	model string
	price float64
	dpi   int
}

func NewMouse(model string, price float64, dpi int) *Mouse {
	return &Mouse{model: model, price: price, dpi: dpi}
}

func (this *Mouse) GetModel() string {
	return this.model
}

func (this *Mouse) GetPrice() float64 {
	return this.price
}

func (this *Mouse) GetDescription() string {
	return fmt.Sprintf("Mouse - Model %s, Price %.2f has %d dpi.", this.model, this.price, this.dpi)
}
