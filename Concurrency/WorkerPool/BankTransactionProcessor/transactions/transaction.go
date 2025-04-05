package transactions

import "BankTransactionProcessor/bankAccountRepository"

type Transaction interface {
	Execute(repository bankAccountRepository.BankAccountRepository) error
}
