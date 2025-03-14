package builders

type Builder interface {
	setDestination()
	setDuration()
	setAccommodation()
	setTransport()
	addActivity()
	setPrice()
	getTourPackage() *TourPackage
}

func CreateBuilder(tourType string) Builder {
	if tourType == "adventure" {
		return newAdventureTourBuilder()
	} else if tourType == "luxury" {
		return newLuxuryTourBuilder()
	}
	return nil
}
