package expression

import (
	"regexp"
)

type Calculator struct {
	expr Expression
}

func NewCalculator(toParse string) *Calculator {
	re := regexp.MustCompile(`\s+`)
	toParse = re.ReplaceAllString(toParse, "")
	return &Calculator{expr: parse(toParse)}
}

func (this *Calculator) Evaluate() float64 {
	return this.expr.Eval()
}
