package builders

import "fmt"

type TourPackage struct {
	destination         string
	durationDays        int
	typeOfAccommodation string
	meanOfTransport     string
	activities          []string
	price               int
}

func (tP *TourPackage) ShowInfo() {
	fmt.Printf("Destination city: %s\n", tP.destination)
	fmt.Printf("Duration: %d\n", tP.durationDays)
	fmt.Printf("Type of accommodation: %s\n", tP.typeOfAccommodation)
	fmt.Printf("Mean of transport: %s\n", tP.meanOfTransport)
	fmt.Printf("Available activites: \n")
	for index, activity := range tP.activities {
		fmt.Printf("%d. %s\n", index+1, activity)
	}
	fmt.Printf("Price: %d\n", tP.price)
}
