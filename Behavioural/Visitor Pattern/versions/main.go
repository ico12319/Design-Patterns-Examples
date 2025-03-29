package main

import (
	"fmt"
	"versions/versions"
)

func getMaxVersion(vers []string) string {
	var maxVersion versions.Version
	for i := 0; i < len(vers); i++ {
		if versions.IsValidSemVersion(vers[i]) {
			maxVersion = versions.CraftVersion(vers[i])
			break
		}
	}

	for i := 1; i < len(vers); i++ {
		if versions.IsValidSemVersion(vers[i]) {
			craftedVersion := versions.CraftVersion(vers[i])
			if !versions.CompareVersions(maxVersion, craftedVersion) {
				maxVersion = craftedVersion
			}
		}
	}
	if maxVersion != nil {
		return maxVersion.GetTextRepresentation()
	}

	return ""
}

func main() {
	vers := []string{
		"1.0.0",
		"1.0.1",
		"1.2.3",
		"2.0.0",
		"2.0.0-alpha",
		"2.0.0+build",
		"2.0.0-alpha+001",
		"1.0.0-beta",
		"3.1.4",
		"3.1.5",
		"3.1.5-alpha",
		"3.1.5+exp.sha.5114f85",
		"0.9.9",
		"01.0.0",
		"3.2.0",
		"3.2.0-beta",
		"3.2.1",
		"3.2.1+build.1",
		"3.10.2",
		"invalid.version",
		"3.10.2-alpha",
		"3.10.2+build",
		"4.0.0",
		"4.0.0-alpha",
		"4.0.0+build",
	}
	fmt.Println(getMaxVersion(vers))
}
