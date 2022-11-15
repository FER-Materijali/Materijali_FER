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

func main() {
	numbers := [][]int{
		[]int{9, 12},
		[]int{3, 4},
	}
	solution := sretanBroj(numbers)
	fmt.Println(solution)
}

func sretanBroj(matrica [][]int) int {

	CounterMap := make(map[int]int)

	for row := range matrica {
		min := matrica[row][0]
		// check if there is smaller number in a row, if there is, set that number as minimum
		for column := range matrica[row] {
			if matrica[row][column] < min {
				min = matrica[row][column]
			}
		}
		CounterMap[min]++
	}

	for column := range matrica[0] {
		max := matrica[0][column]
		// check if there is greater number in a column, if there is, set that number as maximum
		for row := range matrica {
			if matrica[row][column] > max {
				max = matrica[row][column]
			}
		}
		CounterMap[max]++

	}

	var luckynum int
	for key, value := range CounterMap {
		// find the key that is mapped to value 2 and set that key as our lucky number
		if value == 2 {
			luckynum = key
		}
	}
	return luckynum
}
