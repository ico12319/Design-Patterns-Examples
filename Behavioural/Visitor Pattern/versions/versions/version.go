package versions

type Version interface {
	Accepts(other VersionVisitor) bool
	CompareToBasicSem(other *BasicSemVersion) bool
	CompareToExtendedSem(other *ExtendedSemVersion) bool
	GetTextRepresentation() string
}
