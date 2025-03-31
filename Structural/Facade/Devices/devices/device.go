package devices

type Device interface {
	GetModel() string
	GetPrice() float64
	GetDescription() string
}
