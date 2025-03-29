package versions

type VersionVisitor interface {
	VisitBasic(other *BasicSemVersion) bool
	VisitExtended(other *ExtendedSemVersion) bool
}
