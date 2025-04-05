package transactions

import (
	"BankTransactionProcessor/bankAccountRepository"
	"fmt"
)

type WithdrawTransaction struct {
	accountId      string
	withdrawAmount float64
}

func NewWithdrawTransaction(accountId string, withdrawAmount float64) *WithdrawTransaction {
	return &WithdrawTransaction{accountId: accountId, withdrawAmount: withdrawAmount}
}

func (wTransaction *WithdrawTransaction) Execute(repository bankAccountRepository.BankAccountRepository) error {
	currAccount, err := repository.GetAccount(wTransaction.accountId)
	if err != nil {
		return err
	}
	currBalance := currAccount.GetBalance()
	newBalance := currBalance - wTransaction.withdrawAmount
	currAccount.SetBalance(newBalance)
	fmt.Printf("You successfully withdrew %.2f$ in account %s\n", wTransaction.withdrawAmount, wTransaction.accountId)
	return nil
}
