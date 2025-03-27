package expression

import "math"

type Exponentiation struct {
	left  Expression
	right Expression
}

func NewExponentiation(left Expression, right Expression) *Exponentiation {
	return &Exponentiation{left: left, right: right}
}

func (this *Exponentiation) Eval() float64 {
	return math.Pow(this.left.Eval(), this.right.Eval())
}
