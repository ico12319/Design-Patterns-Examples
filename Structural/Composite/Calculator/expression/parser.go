package expression

import (
	"strconv"
)

func isOperation(symbol uint8) bool {
	return symbol == '*' || symbol == '+' || symbol == '-' || symbol == '^' || symbol == '/'
}

func isExpressionEnclosed(expr string) bool {
	if len(expr) == 0 || expr[0] != '(' || expr[len(expr)-1] != ')' {
		return false
	}
	countBrackets := 0
	for i := 0; i < len(expr); i++ {
		if expr[i] == '(' {
			countBrackets++
		} else if expr[i] == ')' {
			countBrackets--
		}
		if countBrackets == 0 && i < len(expr)-1 {
			return false
		}
	}
	return countBrackets == 0
}

func isUnaryMinus(expr string, index int) bool {
	if index == 0 {
		return true
	}
	return expr[index-1] == '(' || isOperation(expr[index-1])
}

func parse(expr string) Expression {
	if isExpressionEnclosed(expr) {
		expr = expr[:len(expr)-1] // this is not allocating a new string!
		expr = expr[1:len(expr)]
	}

	parsedValue, err := strconv.ParseFloat(expr, 64)
	if err == nil {
		return NewNumberSingleton(parsedValue)
	}

	nestedBrackets := 0
	for i := 0; i < len(expr); i++ {
		if expr[i] == '(' {
			nestedBrackets++
		} else if expr[i] == ')' {
			nestedBrackets--
		}
		if nestedBrackets == 0 {
			if expr[i] == '+' {
				leftSubstr := expr[:i]
				rightSubstr := expr[i+1 : len(expr)]
				return NewAddition(parse(leftSubstr), parse(rightSubstr))
			} else if expr[i] == '-' {
				if isUnaryMinus(expr, i) {
					continue
				}

				leftSubstr := expr[:i]
				rightSubstr := expr[i+1 : len(expr)]
				return NewSubtraction(parse(leftSubstr), parse(rightSubstr))
			} else if expr[i] == '*' {
				leftSubstr := expr[:i]
				rightSubstr := expr[i+1 : len(expr)]
				return NewMultiplication(parse(leftSubstr), parse(rightSubstr))
			} else if expr[i] == '/' {
				leftSubstr := expr[:i]
				rightSubstr := expr[i+1 : len(expr)]
				parsedRightExpr := parse(rightSubstr)
				if parsedRightExpr.Eval() == 0 {
					panic("Division by zero!")
				}
				return NewDivision(parse(leftSubstr), parsedRightExpr)
			} else if expr[i] == '^' {
				leftSubstr := expr[:i]
				rightSubstr := expr[i+1 : len(expr)]
				return NewExponentiation(parse(leftSubstr), parse(rightSubstr))
			}
		}
	}
	return nil
}
