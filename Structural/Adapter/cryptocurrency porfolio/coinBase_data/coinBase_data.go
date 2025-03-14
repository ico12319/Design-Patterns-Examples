package coinBase_data

import (
	"cryptocurrency_porfolio/coinBase_currencies"
	"cryptocurrency_porfolio/coinBase_trades"
	"encoding/json"
	"log"
	"os"
)

type CoinBaseData struct {
	Total      string
	Currencies []coinBase_currencies.CoinBaseCurrencies
	Trades     []coinBase_trades.CoinBaseTrades
}

func CreateRawCoinBaseData(jsonFileName string) *CoinBaseData {
	data, err := os.ReadFile(jsonFileName)
	if err != nil {
		log.Fatal("Error when reading the JSON file.", err)
	}
	var rawCoinBaseData CoinBaseData
	err = json.Unmarshal(data, &rawCoinBaseData)
	if err != nil {
		log.Fatal("Error when parsing the JSON data", err)
	}
	return &rawCoinBaseData
}
