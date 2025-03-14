package portfolio_factory

import (
	"cryptocurrency_porfolio/binance_adapter"
	"cryptocurrency_porfolio/coinBase_adapter"
	"cryptocurrency_porfolio/portfolio"
	"errors"
)

func PortfolioFactory(provider string, jsonFileName string) (portfolio.Portfolio, error) {
	if provider == "binance" {
		return binance_adapter.NewBinanceAdapter(jsonFileName), nil
	}
	if provider == "coinBase" {
		return coinBase_adapter.NewCoinBaseAdapter(jsonFileName), nil
	}
	err := errors.New("Invalid provider!")
	return nil, err
}
