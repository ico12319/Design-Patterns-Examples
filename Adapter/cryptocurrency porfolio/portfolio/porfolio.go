package portfolio

import "cryptocurrency_porfolio/transaction"

type Portfolio interface {
	GetTotalBalance() float64
	GetAssets() map[string]float64
	GetTransactions() []transaction.Transaction
}
