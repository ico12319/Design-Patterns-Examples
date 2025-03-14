package transaction

type Transaction struct {
	Id     string
	Type   string
	Asset  string
	Amount float64
}

func NewTransaction(id string, t string, asset string, amount float64) *Transaction {
	return &Transaction{Id: id, Type: t, Asset: asset, Amount: amount}
}
