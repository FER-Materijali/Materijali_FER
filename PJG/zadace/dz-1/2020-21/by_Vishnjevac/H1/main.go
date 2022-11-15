package main

import (
	"errors"
	"fmt"
	"math"
)

var errNoData = errors.New("no data in list")

type ShopItem struct {
	Name     string
	Price    int
	Callory  int64
	Quantity int
}

func main() {
	shopList := []ShopItem{
		{"Hosomaki Ginger", 54, 250, 1},
		{"Mlijecna cokolada", 8, 600, 3},
		{"Banana", 10, 150, 6},
	}

	tCal := totalCallory(shopList)
	fmt.Println(tCal) // 2950

	best, err := mostHealthy(shopList)
	fmt.Println(best) // [{Banana 10 150 6}]

	fmt.Println(err) // nil
}
func totalCallory(shoppingList []ShopItem) (total int) {
	for _, item := range shoppingList {
		total += int(item.Callory) * item.Quantity
	}

	return total
}
func mostHealthy(shoppingList []ShopItem) (items []ShopItem, err error) {
	var smallest int64
	smallest = math.MaxInt16

	if len(shoppingList) == 0 {
		return nil, errNoData
	}

	for _, item := range shoppingList {
		if item.Callory <= smallest {
			smallest = item.Callory
			items = append(items, item)

			//going over items list to check if we are the smallest
			for i, y := range items {
				//finding if there is a more caloric item
				if y.Callory > item.Callory {
					//removing that one from items
					copy(items[i:], items[i+1:])
					items[len(items)-1] = ShopItem{}
					items = items[:len(items)-1]
				}
			}
		}
	}
	return items, nil
}
