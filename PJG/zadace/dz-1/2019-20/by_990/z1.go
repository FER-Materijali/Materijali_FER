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
	numbers := []int{1, 2, 3, 4, 5, 1, 1, 1}
	solution := counter(numbers)
	fmt.Println(solution)
}
func counter(numbers []int) map[int]int {

	// initiate the counting map
	CounterMap := make(map[int]int)

	// loop through the slice numbers
	for _, value := range numbers {
		// store each number as a key in map
		// increase it value by 1 every time it reappears in the slice
		CounterMap[value]++
	}

	// return the map
	return CounterMap
}
