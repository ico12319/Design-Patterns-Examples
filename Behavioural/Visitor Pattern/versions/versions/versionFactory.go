package versions

import "strings"

func CraftVersion(versionString string) Version {
	if strings.Contains(versionString, "+") || strings.Contains(versionString, "-") {
		return NewExtendedSemVersion(versionString)
	}
	return NewBasicSemVersion(versionString)
}
