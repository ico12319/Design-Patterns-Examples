package task

import (
	"fmt"
	"strings"
	"sync"
)

type CompositeTask struct {
	tasks []Task
}

func NewCompositeTask(t []Task) *CompositeTask {
	return &CompositeTask{tasks: t}
}

func (cT *CompositeTask) Execute() (string, error) {
	var wg sync.WaitGroup

	resChn := make(chan string, len(cT.tasks)) /* we are making the channel buffered because if we don't make
	it buffered the sends would block until a receiver reads the data */
	errChan := make(chan error, len(cT.tasks))

	for i := 0; i < len(cT.tasks); i++ {
		wg.Add(1)
		go func(t Task) {
			defer wg.Done()
			response, err := t.Execute()
			fmt.Println(response)
			if err != nil {
				errChan <- err // sending an error to the errChannel
			} else {
				resChn <- response // sending a responses to the resChannel
			}
		}(cT.tasks[i])
	}
	wg.Wait()
	close(resChn)  // we are closing the channel so we can't send more messages to the channel
	close(errChan) // we are closing the channel so we can't send more messages to the channel

	if len(errChan) > 0 {
		return "", <-errChan
	}

	var sb strings.Builder // using strings.Builder for efficient concatenation(mutable)
	for r := range resChn {
		sb.WriteString(r)
		sb.WriteString(": ")
	}
	res := sb.String()
	return res, nil
}
