package versions

import (
	"regexp"
	"strconv"
)

func parseParts(verisonString []string) (int64, int64, int64) {
	majPart, _ := strconv.ParseInt(verisonString[0], 0, 64)
	minPart, _ := strconv.ParseInt(verisonString[1], 0, 64)
	pPart, _ := strconv.ParseInt(verisonString[2], 0, 64)
	return majPart, minPart, pPart
}

func extractNumber(versionString string, startIndex int) int64 {
	var extractedNumber int64 = 0
	for i := startIndex; i < len(versionString); i++ {
		if versionString[i] == '.' {
			break
		}
		parsedDigit, _ := strconv.Atoi(string(versionString[i]))
		extractedNumber = (extractedNumber * 10) + int64(parsedDigit)
	}
	return extractedNumber
}

func IsValidSemVersion(versionString string) bool {
	var semVerRegex = regexp.MustCompile(`^(0|[1-9]\d*)\.(0|[1-9]\d*)\.(0|[1-9]\d*)(?:-((?:0|[1-9]\d*|[A-Za-z-][0-9A-Za-z-]*)(?:\.(?:0|[1-9]\d*|[A-Za-z-][0-9A-Za-z-]*))*))?(?:\+([0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?$`)
	return semVerRegex.MatchString(versionString)
}

func CompareVersions(lhs Version, rhs Version) bool {
	visitor := NewCompareVisitor(lhs)
	return rhs.Accepts(visitor)
}
