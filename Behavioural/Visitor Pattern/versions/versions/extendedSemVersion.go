package versions

import (
	"strings"
	"unicode"
)

type ExtendedSemVersion struct {
	majorPart      int64
	minorPart      int64
	patchPart      int64
	preReleasePart string
	originalText   string
}

func NewExtendedSemVersion(versionStr string) *ExtendedSemVersion {
	var pRelease string
	spliitedParts := strings.SplitN(versionStr, "+", 2)
	splittedAroundMinus := strings.Split(spliitedParts[0], "-")
	splittedAroundDot := strings.Split(splittedAroundMinus[0], ".")
	majPart, minPart, pPart := parseParts(splittedAroundDot)
	if len(splittedAroundMinus) == 2 {
		pRelease = splittedAroundMinus[1]
	}
	return &ExtendedSemVersion{majorPart: majPart, minorPart: minPart, patchPart: pPart, preReleasePart: pRelease, originalText: versionStr}
}

func (this *ExtendedSemVersion) Accepts(other VersionVisitor) bool {
	return other.VisitExtended(this)
}

func (this *ExtendedSemVersion) CompareToBasicSem(other *BasicSemVersion) bool {
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

func (this *ExtendedSemVersion) CompareToExtendedSem(other *ExtendedSemVersion) bool {
	if this.majorPart != other.majorPart {
		return this.majorPart > other.majorPart
	}
	if this.minorPart != other.minorPart {
		return this.minorPart > other.minorPart
	}
	if this.patchPart != other.patchPart {
		return this.patchPart > other.patchPart
	}

	if len(this.preReleasePart) == 0 {
		return false
	}
	if len(other.preReleasePart) == 0 {
		return true
	}

	minSize := min(len(this.preReleasePart), len(other.preReleasePart))
	for i := 0; i < minSize; i++ {
		if unicode.IsDigit(rune(this.preReleasePart[i])) && unicode.IsDigit(rune(other.preReleasePart[i])) {
			thisFormedNumber := extractNumber(this.preReleasePart, i)
			otherFormedNumber := extractNumber(other.preReleasePart, i)
			if thisFormedNumber != otherFormedNumber {
				return thisFormedNumber > otherFormedNumber
			}
		} else if unicode.IsDigit(rune(this.preReleasePart[i])) && !unicode.IsDigit(rune(other.preReleasePart[i])) {
			return true
		} else if !unicode.IsDigit(rune(this.preReleasePart[i])) && unicode.IsDigit(rune(other.preReleasePart[i])) {
			return false
		}
		if this.preReleasePart[i] != other.preReleasePart[i] {
			return this.preReleasePart[i] > other.preReleasePart[i]
		}
	}

	return len(this.preReleasePart) > len(other.preReleasePart)
}

func (this *ExtendedSemVersion) GetTextRepresentation() string {
	return this.originalText
}
