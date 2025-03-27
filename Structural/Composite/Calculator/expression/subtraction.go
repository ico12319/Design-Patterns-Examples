package expression

type Subtraction struct {
	left  Expression
	right Expression
}

func NewSubtraction(left Expression, right Expression) *Subtraction {
	return &Subtraction{left: left, right: right}
}

func (this *Subtraction) Eval() float64 {
	return this.left.Eval() - this.right.Eval()
}
