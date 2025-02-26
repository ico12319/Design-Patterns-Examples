package coinBase_adapter

import (
	"cryptocurrency_porfolio/coinBase_data"
	"cryptocurrency_porfolio/transaction"
	"log"
	"strconv"
)

type CoinBaseAdapter struct {
	data *coinBase_data.CoinBaseData
}

func NewCoinBaseAdapter(jsonFileName string) *CoinBaseAdapter {
	d := coinBase_data.CreateRawCoinBaseData(jsonFileName)
	return &CoinBaseAdapter{data: d}
}

func (c *CoinBaseAdapter) GetTotalBalance() float64 {
	stringTotalBalance := c.data.Total
	f, err := strconv.ParseFloat(stringTotalBalance, 64)
	if err != nil{
		log.Fatal("Error when trying to parse the data",err)
	}
	return f
}

func (c *CoinBaseAdapter) GetAssets() map[string] float64{
	symbolBalance := make(map[string] float64)
	for _,curr := range c.data.Currencies{
		strAmount := curr.Balance
		f,err := strconv.ParseFloat(strAmount,64)
		if err != nil{
			log.Fatal("Error when trying to parse the data",err)
		}
		symbolBalance[curr.Symbol] = f
	}
	return symbolBalance
}

func (c *CoinBaseAdapter) GetTransactions() []transaction.Transaction{
	transactions := make([] transaction.Transaction,0,8)
	for _,t := range c.data.Trades{
		parsedQuantity,err := strconv.ParseFloat(t.Quantity,64)
		if err != nil{
			log.Fatal("Error when trying to parse the data",err)
		}
		trans := transaction.NewTransaction(t.TradeId,t.Action,t.Currency,parsedQuantity)
		transactions = append(transactions,*trans)
	}
	return transactions
}