package bankAccount

import (
	"fmt"
	"sync"
)

type BankAccount struct {
	id      string
	balance float64
	mu      sync.Mutex
}

func NewBankAccount(id string, balance float64) *BankAccount {
	return &BankAccount{id: id, balance: balance}
}

func (bAccount *BankAccount) SetId(id string) {
	bAccount.mu.Lock()
	defer bAccount.mu.Unlock()

	bAccount.id = id
}

func (bAccount *BankAccount) SetBalance(balance float64) {
	bAccount.mu.Lock()
	defer bAccount.mu.Unlock()

	bAccount.balance = balance
}

func (bAccount *BankAccount) GetId() string {
	bAccount.mu.Lock()
	defer bAccount.mu.Unlock()

	return bAccount.id
}

func (bAccount *BankAccount) GetBalance() float64 {
	bAccount.mu.Lock()
	defer bAccount.mu.Unlock()

	return bAccount.balance
}

func (bAccount *BankAccount) GetBankAccountInfo() {
	bAccount.mu.Lock()
	defer bAccount.mu.Unlock()

	fmt.Printf("Account with %s id has %.2f$\n", bAccount.id, bAccount.balance)
}
