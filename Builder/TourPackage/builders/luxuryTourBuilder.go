package builders

type LuxuryTourBuilder struct {
	destination         string
	durationDays        int
	typeOfAccommodation string
	meanOfTransport     string
	activities          []string
	price               int
}

func (aTB *LuxuryTourBuilder) getTourPackage() *TourPackage {
	return &TourPackage{
		destination:         aTB.destination,
		durationDays:        aTB.durationDays,
		typeOfAccommodation: aTB.typeOfAccommodation,
		meanOfTransport:     aTB.meanOfTransport,
		activities:          aTB.activities,
		price:               aTB.price}
}

func newLuxuryTourBuilder() *LuxuryTourBuilder {
	return &LuxuryTourBuilder{"", 0, "", "", make([]string, 0, 8), 0}
}

func (aTB *LuxuryTourBuilder) setDestination() {
	aTB.destination = "Canary Islands"
}

func (aTB *LuxuryTourBuilder) setDuration() { // Luxury tours are shorter because they are meant for you to relax yourself for a few days and charge your batteries also they are more expensive
	aTB.durationDays = 3
}

func (aTB *LuxuryTourBuilder) setAccommodation() {
	aTB.typeOfAccommodation = "Five star hotel"
}

func (aTB *LuxuryTourBuilder) setTransport() { //Luxury tours are usually more expensive so you can travel by plane
	aTB.meanOfTransport = "plane"
}

func (aTB *LuxuryTourBuilder) setPrice() {
	aTB.price = 2000
}

func (aTB *LuxuryTourBuilder) addActivity() {
	aTB.activities = append(aTB.activities, "SPA")
	aTB.activities = append(aTB.activities, "Swimming")
	aTB.activities = append(aTB.activities, "Yoga")
	aTB.activities = append(aTB.activities, "Water sports")
	aTB.activities = append(aTB.activities, "Culinary classes")
}
