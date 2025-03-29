package versions

type CompareVisitor struct {
	lhs Version
}

func NewCompareVisitor(lhs Version) *CompareVisitor {
	return &CompareVisitor{lhs: lhs}
}

func (this *CompareVisitor) VisitBasic(other *BasicSemVersion) bool {
	return this.lhs.CompareToBasicSem(other)
}

func (this *CompareVisitor) VisitExtended(other *ExtendedSemVersion) bool {
	return this.lhs.CompareToExtendedSem(other)
}
