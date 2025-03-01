package task

import (
	"errors"
	"time"
)

type PaymentTask struct {
	amount float64
}

func NewPaymentTask(am float64) *PaymentTask {
	return &PaymentTask{amount: am}
}

func (pT *PaymentTask) Execute() (string, error) {
	time.Sleep(time.Second) // simulates processing
	if pT.amount < 0 {
		return "", errors.New("payment failed. invalid amount")
	}
	return "Payment confirmed.", nil
}
