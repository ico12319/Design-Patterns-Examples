package expression

type NumberSingleton struct {
	val float64
}

func NewNumberSingleton(val float64) *NumberSingleton {
	return &NumberSingleton{val: val}
}

func (this *NumberSingleton) Eval() float64 {
	return this.val
}
