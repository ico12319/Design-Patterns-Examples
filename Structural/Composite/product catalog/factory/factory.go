package factory

import (
	"fmt"
	"product_catalog/catalog"
	"product_catalog/category"
	"product_catalog/product"
	"product_catalog/raw_item"
)

func createCatalogHelper(dummyRawItem *raw_item.RawItem) (catalog.Catalog, error) {
	if dummyRawItem.Type == "product" {
		return product.NewProduct(dummyRawItem.Name, dummyRawItem.Price), nil
	} else if dummyRawItem.Type == "category" {
		name := dummyRawItem.Name
		children := make([]catalog.Catalog, 0)
		for _, c := range dummyRawItem.Children {
			childrenObj, err := createCatalogHelper(&c)
			if err != nil {
				return nil, err
			}
			children = append(children, childrenObj)
		}
		return category.NewCategory(name, children), nil
	} else {
		return nil, fmt.Errorf("unknown item type: %s", dummyRawItem.Type)
	}
}

func CreateCatalog(jsonFileName string) (catalog.Catalog, error) {
	rawItem := raw_item.CreateRawItem(jsonFileName)
	return createCatalogHelper(rawItem)
}
