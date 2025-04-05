package transactions

import (
	"BankTransactionProcessor/bankAccountRepository"
	"sync"
)

type WorkerPool struct {
	transactions        []Transaction
	workers             int
	transactionsChannel chan Transaction
	wg                  sync.WaitGroup
}

func NewWorkerPool(transactions []Transaction, workers int) *WorkerPool {
	return &WorkerPool{transactions: transactions, workers: workers, transactionsChannel: make(chan Transaction, len(transactions))}
}

func (wPool *WorkerPool) Work(repository bankAccountRepository.BankAccountRepository) error {
	for transaction := range wPool.transactionsChannel {
		err := transaction.Execute(repository)
		if err != nil {
			return err
		}
		wPool.wg.Done()
	}
	return nil
}

func (wPool *WorkerPool) Run(repository bankAccountRepository.BankAccountRepository) error {
	for i := 0; i < wPool.workers; i++ {
		go wPool.Work(repository)
	}
	wPool.wg.Add(len(wPool.transactions))
	for i := 0; i < len(wPool.transactions); i++ {
		wPool.transactionsChannel <- wPool.transactions[i]
	}

	close(wPool.transactionsChannel)
	wPool.wg.Wait()
	return nil
}
