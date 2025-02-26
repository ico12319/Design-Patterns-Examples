package main

import (
	"cryptocurrency_porfolio/portfolio_factory"
	"fmt"
	"log"
)

//TIP <p>To run your code, right-click the code and select <b>Run</b>.</p> <p>Alternatively, click
// the <icon src="AllIcons.Actions.Execute"/> icon in the gutter and select the <b>Run</b> menu item from here.</p>

func main() {

	portfolio, err := portfolio_factory.PortfolioFactory("binance", "binance_json.json")
	if err != nil {
		log.Fatal("Error", err)
	}
	fmt.Println(portfolio.GetTotalBalance())
	fmt.Println(portfolio.GetAssets())

	portfolio2, err2 := portfolio_factory.PortfolioFactory("coinBase", "coinBase_json.json")
	if err2 != nil {
		log.Fatal("Error", err2)
	}
	fmt.Println(portfolio2.GetTotalBalance())
}
