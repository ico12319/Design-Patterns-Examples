package versions

import (
	"strconv"
	"strings"
)

type BasicSemVersion struct {
	majorPart    int64
	minorPart    int64
	patchPart    int64
	originalText string
}

func NewBasicSemVersion(versionString string) *BasicSemVersion {
	splittedParts := strings.Split(versionString, ".")
	majPart, _ := strconv.ParseInt(splittedParts[0], 0, 64)
	minPart, _ := strconv.ParseInt(splittedParts[1], 0, 64)
	pPart, _ := strconv.ParseInt(splittedParts[2], 0, 64)
	return &BasicSemVersion{majorPart: majPart, minorPart: minPart, patchPart: pPart, originalText: versionString}
}

func (this *BasicSemVersion) Accepts(other VersionVisitor) bool {
	return other.VisitBasic(this)
}

// 1.0.0 / 1.0.1 -> after function call -> 1.0.1 / 1.0.0
func (this *BasicSemVersion) CompareToBasicSem(other *BasicSemVersion) bool {
	if this.majorPart != other.majorPart {
		return this.majorPart > other.majorPart
	}
	if this.minorPart != other.minorPart {
		return this.minorPart > other.minorPart
	}
	if this.patchPart != other.patchPart {
		return this.patchPart > other.patchPart
	}
	return false
}

// 1.0.1 / 1.0.1-aplpha
func (this *BasicSemVersion) CompareToExtendedSem(other *ExtendedSemVersion) bool {
	if this.majorPart != other.majorPart {
		return this.majorPart > other.majorPart
	}
	if this.minorPart != other.minorPart {
		return this.minorPart > other.minorPart
	}
	if this.patchPart != other.patchPart {
		return this.patchPart > other.patchPart
	}
	return true
}

func (this *BasicSemVersion) GetTextRepresentation() string {
	return this.originalText
}
