package expression

type Addition struct {
	left  Expression
	right Expression
}

func NewAddition(left Expression, right Expression) *Addition {
	return &Addition{left: left, right: right}
}

func (this *Addition) Eval() float64 {
	return this.left.Eval() + this.right.Eval()
}
