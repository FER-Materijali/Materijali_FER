//   Copyright 2020 Jakov Smolić
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

package main

import "fmt"

type Shopping struct {
	Name     string
	Price    int
	Quantity int
}

func main() {
	shopList := []Shopping{
		Shopping{"kruh", 8, 2},
		Shopping{"mlijeko", 15, 1}}
	//var shopList []Shopping //---> nil
	// := []Shopping{} //---> empty
	solution1, err := mostExpensive(shopList)
	fmt.Println(solution1) //mlijeko
	fmt.Println(err)       // nil
	solution2 := totalCost(shopList)
	fmt.Println(solution2) // 31
}

func mostExpensive(shopList []Shopping) (item []Shopping, err error) {

	if shopList == nil {
		err = fmt.Errorf("no data")
		return nil, err
	}

	max := 0
	for i := range shopList {
		if shopList[i].Price > max {
			max = shopList[i].Price
		}
	}

	for i := range shopList {
		if shopList[i].Price == max {
			item = append(item, shopList[i])
		}
	}

	return item, err
}

func totalCost(shopList []Shopping) (total int) {

	if shopList == nil || len(shopList) == 0 {
		total = 0
	} else {
		for i := range shopList {
			total = total + shopList[i].Price*shopList[i].Quantity
		}
	}
	return total
}
