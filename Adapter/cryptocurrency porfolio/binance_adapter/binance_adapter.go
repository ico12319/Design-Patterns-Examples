package binance_adapter

import (
	"cryptocurrency_porfolio/binance_data"
	"cryptocurrency_porfolio/transaction"
)

type BinanceAdapter struct {
	data *binance_data.BinanceData
}

func NewBinanceAdapter(jsonFileName string) *BinanceAdapter {
	d := binance_data.CreateRawBinanceData(jsonFileName)
	return &BinanceAdapter{data: d}
}

func (bAdapter *BinanceAdapter) GetTotalBalance() float64 {
	return bAdapter.data.Balance
}

func (bAdapter *BinanceAdapter) GetAssets() map[string]float64 {
	assets := make(map[string]float64)
	for _, a := range bAdapter.data.Assets {
		assets[a.Name] = a.Amount
	}
	return assets
}

func (bAdapter *BinanceAdapter) GetTransactions() []transaction.Transaction {
	transactions := make([]transaction.Transaction, 0, 8)
	for _, t := range bAdapter.data.Transactions {
		trans := transaction.NewTransaction(t.Id, t.Type, t.Asset, t.Amount)
		transactions = append(transactions, *trans)
	}
	return transactions

}
