package catalog

type Catalog interface {
	GetPrice() int
	GetName() string
	PrintDetails()
	Contains(name string) bool
}
