package builders

type Director struct {
	builder Builder
}

func NewDirector(builder Builder) *Director {
	return &Director{builder: builder}
}

func (director *Director) BuildTourPackage() *TourPackage {
	director.builder.setDestination()
	director.builder.setDuration()
	director.builder.setAccommodation()
	director.builder.setTransport()
	director.builder.addActivity()
	director.builder.setPrice()
	return director.builder.getTourPackage()
}
