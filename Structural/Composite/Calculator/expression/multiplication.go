package expression

type Multiplication struct {
	left  Expression
	right Expression
}

func NewMultiplication(left Expression, right Expression) *Multiplication {
	return &Multiplication{left: left, right: right}
}

func (this *Multiplication) Eval() float64 {
	return this.left.Eval() * this.right.Eval()
}
