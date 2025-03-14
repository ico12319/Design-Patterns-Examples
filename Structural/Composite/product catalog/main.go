package main

import (
	"fmt"
	"product_catalog/factory"
)

func main() {
	catalogItem, err := factory.CreateCatalog("parser.json")
	if err != nil {
		fmt.Printf("Error %v", err)
	}
	catalogItem.PrintDetails()
}
