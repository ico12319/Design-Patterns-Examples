package transactions

import (
	"BankTransactionProcessor/bankAccountRepository"
	"fmt"
)

type DepositTransaction struct {
	accountId     string
	depositAmount float64
}

func NewDepositTransaction(accountId string, depositAmount float64) *DepositTransaction {
	return &DepositTransaction{accountId: accountId, depositAmount: depositAmount}
}

func (dTransaction *DepositTransaction) Execute(repository bankAccountRepository.BankAccountRepository) error {
	currAccount, err := repository.GetAccount(dTransaction.accountId)
	if err != nil {
		return err
	}
	currBalance := currAccount.GetBalance()
	newBalance := currBalance + dTransaction.depositAmount
	currAccount.SetBalance(newBalance)
	fmt.Printf("You successfully deposited %.2f$ in account %s\n", dTransaction.depositAmount, dTransaction.accountId)
	return nil
}
