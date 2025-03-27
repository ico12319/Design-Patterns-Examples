package expression

type Division struct {
	left  Expression
	right Expression
}

func NewDivision(left Expression, right Expression) *Division {
	return &Division{left: left, right: right}
}

func (this *Division) Eval() float64 {
	return this.left.Eval() / this.right.Eval()
}
