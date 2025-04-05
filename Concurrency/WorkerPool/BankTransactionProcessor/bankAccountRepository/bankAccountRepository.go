package bankAccountRepository

import "BankTransactionProcessor/bankAccount"

type BankAccountRepository interface {
	AddAccount(account *bankAccount.BankAccount) error
	GetAccount(id string) (*bankAccount.BankAccount, error)
}
