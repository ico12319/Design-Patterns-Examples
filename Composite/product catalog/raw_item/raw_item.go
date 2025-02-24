package raw_item

import (
	"encoding/json"
	"log"
	"os"
)

type RawItem struct {
	Name     string
	Type     string
	Price    int
	Children []RawItem
}

func CreateRawItem(jsonFileName string) *RawItem {
	data, err := os.ReadFile(jsonFileName)

	if err != nil {
		log.Fatal("Error when trying to read the file", err)
	}

	var root RawItem
	err = json.Unmarshal(data, &root)
	if err != nil {
		log.Fatal("Error when parsing the JSON file", err)
	}
	return &root
}
