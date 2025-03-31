package devices

import "fmt"

type Laptop struct {
	model  string
	price  float64
	weight int
}

func NewLaptop(model string, price float64, weight int) *Laptop {
	return &Laptop{model: model, price: price, weight: weight}
}

func (this *Laptop) GetModel() string {
	return this.model
}

func (this *Laptop) GetPrice() float64 {
	return this.price
}

func (this *Laptop) GetDescription() string {
	return fmt.Sprintf("Laptop - Model %s, Price %.2f has %d weight.", this.model, this.price, this.weight)
}
