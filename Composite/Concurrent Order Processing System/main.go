package main

import (
	"Concurrent_Order_Processing_System/task"
	"fmt"
)

//TIP <p>To run your code, right-click the code and select <b>Run</b>.</p> <p>Alternatively, click
// the <icon src="AllIcons.Actions.Execute"/> icon in the gutter and select the <b>Run</b> menu item from here.</p>

func main() {
	iT := task.NewInventoryTask("Dlaka", 12)
	sT := task.NewSchedulingTask("Harambe")
	pT := task.NewPaymentTask(64.4)

	iT2 := task.NewInventoryTask("D", 24)
	sT2 := task.NewSchedulingTask("Hara")
	pT2 := task.NewPaymentTask(70.9)

	tasks := []task.Task{iT, sT, pT}
	cT := task.NewCompositeTask(tasks)

	tasks2 := []task.Task{iT2, sT2, pT2, cT}
	cT2 := task.NewCompositeTask(tasks2)

	str, err := cT2.Execute()
	if err != nil {
		fmt.Printf("Error %v", err)
	}
	fmt.Println(str)
}
