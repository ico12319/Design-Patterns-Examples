package task

import (
	"errors"
	"time"
)

type InventoryTask struct {
	item     string
	quantity int
}

func NewInventoryTask(it string, quan int) *InventoryTask {
	return &InventoryTask{item: it, quantity: quan}
}

func (iT *InventoryTask) Execute() (string, error) {
	time.Sleep(time.Second * 2)
	if iT.quantity < 0 {
		return "", errors.New("empty inventory")
	}
	return "inventory available.", nil
}
