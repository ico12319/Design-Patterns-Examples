package category

import (
	"fmt"
	"product_catalog/catalog"
)

type Category struct {
	name     string
	catalogs []catalog.Catalog
}

func (c *Category) GetName() string {
	return c.name
}

func NewCategory(n string, cLogs []catalog.Catalog) *Category {
	return &Category{name: n, catalogs: cLogs}
}

func (c *Category) GetPrice() int {
	sumPrice := 0
	for _, c := range c.catalogs {
		sumPrice += c.GetPrice()
	}
	return sumPrice
}

func (c *Category) PrintDetails() {
	fmt.Printf("Category: %v (Total: %v)", c.name, c.GetPrice())
	fmt.Println()
	for _, c := range c.catalogs {
		fmt.Print(" ")
		c.PrintDetails()
	}
}

func (c *Category) Contains(n string) bool {
	if c.name == n {
		return true
	}
	for _, c := range c.catalogs {
		if c.Contains(n) {
			return true
		}
	}
	return false
}
