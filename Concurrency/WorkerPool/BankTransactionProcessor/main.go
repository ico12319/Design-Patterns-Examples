package main

import (
	"BankTransactionProcessor/bankAccount"
	"BankTransactionProcessor/bankAccountRepository"
	"BankTransactionProcessor/transactions"
)

func main() {

	repo := bankAccountRepository.GetInstance()
	bAccount1 := bankAccount.NewBankAccount("1454", 100)
	bAccount2 := bankAccount.NewBankAccount("1565", 10000)
	bAccount3 := bankAccount.NewBankAccount("8989", 200000)
	bAccount4 := bankAccount.NewBankAccount("444", 99999)

	err := repo.AddAccount(bAccount1)
	if err != nil {
		panic(err)
	}

	err = repo.AddAccount(bAccount2)
	if err != nil {
		panic(err)
	}

	err = repo.AddAccount(bAccount3)
	if err != nil {
		panic(err)
	}

	err = repo.AddAccount(bAccount4)
	if err != nil {
		panic(err)
	}

	tr1, _ := transactions.CraftTransaction("Deposit", "1454", 200)
	tr2, _ := transactions.CraftTransaction("Deposit", "1565", 50)
	tr3, _ := transactions.CraftTransaction("Withdraw", "1454", 50)
	tr4, _ := transactions.CraftTransaction("Deposit", "1454", 400)
	tr5, _ := transactions.CraftTransaction("Withdraw", "8989", 50)
	tr6, _ := transactions.CraftTransaction("Deposit", "1454", 400)
	tr7, _ := transactions.CraftTransaction("Withdraw", "444", 1000)

	trArr := []transactions.Transaction{tr1, tr2, tr3, tr4, tr5, tr6, tr7}

	pool := transactions.NewWorkerPool(trArr, 7)
	err = pool.Run(repo)
	if err != nil {
		panic(err)
	}
}
