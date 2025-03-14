package task

import (
	"errors"
	"time"
)

type SchedulingTask struct {
	address string
}

func NewSchedulingTask(add string) *SchedulingTask {
	return &SchedulingTask{address: add}
}

func (sT *SchedulingTask) Execute() (string, error) {
	time.Sleep(time.Millisecond * 150)
	if sT.address == "" {
		return "", errors.New("invalid address provided")
	}
	return "Delivery scheduled", nil
}
