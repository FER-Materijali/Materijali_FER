package someRandomPackage

import (
	"errors"
)

type ShopItem struct {
	Name     string
	Price    int
	Type     string
	Callory  int64
	Quantity int
}

var (
	errToExpensive = errors.New("Too expensive item")
	errWrongItem   = errors.New("Item not allowed")
	errToCaloric   = errors.New("to much calories")
)

const (
	ToExpensiveLimit = 20
	AllowedType      = "Prehrana"
)

func TotalCost(items []ShopItem) (int, error) {
	total := 0
	for _, v := range items {
		if v.Price*v.Quantity > ToExpensiveLimit {
			return 0, errToExpensive
		}
		if v.Type != AllowedType {
			return 0, errWrongItem
		}
		if v.Callory > 300 {
			return 0, errToCaloric
		}
		total += v.Price * v.Quantity
	}
	return total, nil
}
