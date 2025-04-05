package transactions

import "fmt"

func CraftTransaction(transactionType string, accountId string, amount float64) (Transaction, error) {
	if transactionType == "Deposit" {
		return NewDepositTransaction(accountId, amount), nil
	} else if transactionType == "Withdraw" {
		return NewWithdrawTransaction(accountId, amount), nil
	}
	return nil, fmt.Errorf("invalid transaction type %s\n", transactionType)
}
