package bankAccountRepository

import (
	"BankTransactionProcessor/bankAccount"
	"fmt"
	"sync"
)

type Ledger struct {
	accounts map[string]*bankAccount.BankAccount
	mu       sync.Mutex
}

var instance *Ledger
var once sync.Once

func GetInstance() *Ledger {
	once.Do(func() {
		instance = &Ledger{accounts: make(map[string]*bankAccount.BankAccount)}
	})
	return instance
}

func (l *Ledger) AddAccount(account *bankAccount.BankAccount) error {
	if account == nil {
		return fmt.Errorf("can't add invalid account in the ledger")
	}
	l.mu.Lock()
	defer l.mu.Unlock()

	l.accounts[account.GetId()] = account
	return nil
}

func (l *Ledger) GetAccount(id string) (*bankAccount.BankAccount, error) {
	l.mu.Lock()
	defer l.mu.Unlock()

	acc, isContained := l.accounts[id]
	if !isContained {
		return nil, fmt.Errorf("trying to access invalid bank account with %s\n", id)
	}
	return acc, nil
}
