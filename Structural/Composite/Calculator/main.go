package main

import (
	"Calculator/expression"
	"fmt"
)

func main() {
	calc := expression.NewCalculator("(5 + 12 * (4 + (4 ^ (6 + 1))))")
	calc2 := expression.NewCalculator("(12.45 + 4)")
	calc3 := expression.NewCalculator("(6 + (9 * 4))")

	calc5 := expression.NewCalculator("((-12 + 8) * (-2))")

	fmt.Println(calc5.Evaluate())

	fmt.Println(calc.Evaluate())
	fmt.Println(calc2.Evaluate())
	fmt.Println(calc3.Evaluate())
}
