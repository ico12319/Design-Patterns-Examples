package binance_data

import (
	"cryptocurrency_porfolio/binance_asset"
	"cryptocurrency_porfolio/binance_transaction"
	"encoding/json"
	"log"
	"os"
)

type BinanceData struct {
	Balance      float64
	Assets       []binance_asset.BinanceAsset
	Transactions []binance_transaction.BinanceTransaction
}

func CreateRawBinanceData(jsonFileName string) *BinanceData {
	data, err := os.ReadFile(jsonFileName)
	if err != nil {
		log.Fatal("Error when reading the JSON file!", err)
	}

	var rawBinanceData BinanceData
	err = json.Unmarshal(data, &rawBinanceData)
	if err != nil {
		log.Fatal("Error when parsing the JSON file!", err)
	}
	return &rawBinanceData
}
