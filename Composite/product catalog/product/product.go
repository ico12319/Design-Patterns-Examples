package product

import (
	"fmt"
)

type Product struct {
	name  string
	price int
}

func NewProduct(n string, p int) *Product {
	return &Product{name: n, price: p}
}

func (p *Product) GetName() string {
	return p.name
}

func (p *Product) GetPrice() int {
	return p.price
}

func (p *Product) Contains(n string) bool {
	return p.GetName() == n
}

func (p *Product) PrintDetails() {
	fmt.Printf(" - Product: %v price: %v", p.name, p.GetPrice())
	fmt.Println()
}
