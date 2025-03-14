package builders

type AdventureTourBuilder struct {
	destination         string
	durationDays        int
	typeOfAccommodation string
	meanOfTransport     string
	activities          []string
	price               int
}

func (aTB *AdventureTourBuilder) getTourPackage() *TourPackage {
	return &TourPackage{
		destination:         aTB.destination,
		durationDays:        aTB.durationDays,
		typeOfAccommodation: aTB.typeOfAccommodation,
		meanOfTransport:     aTB.meanOfTransport,
		activities:          aTB.activities,
		price:               aTB.price,
	}
}

func newAdventureTourBuilder() *AdventureTourBuilder {
	return &AdventureTourBuilder{"", 0, "", "", make([]string, 0, 8), 0}
}

func (aTB *AdventureTourBuilder) setDestination() {
	aTB.destination = "Australia"
}

func (aTB *AdventureTourBuilder) setDuration() { // Adventure tours are longer so you can explore more things
	aTB.durationDays = 10
}

func (aTB *AdventureTourBuilder) setAccommodation() {
	aTB.typeOfAccommodation = "camping"
}

func (aTB *AdventureTourBuilder) setTransport() { //Adventure tours are usually cheaper
	aTB.meanOfTransport = "bus"
}

func (aTB *AdventureTourBuilder) setPrice() {
	aTB.price = 250
}

func (aTB *AdventureTourBuilder) addActivity() {
	aTB.activities = append(aTB.activities, "Rafting")
	aTB.activities = append(aTB.activities, "SkyDiving")
	aTB.activities = append(aTB.activities, "Canoeing")
	aTB.activities = append(aTB.activities, "Jet Boating")
	aTB.activities = append(aTB.activities, "Bungee jumping")
}
