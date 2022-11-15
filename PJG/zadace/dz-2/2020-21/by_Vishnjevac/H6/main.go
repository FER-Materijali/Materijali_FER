package main

import (
	"errors"
	"fmt"
	"math"
	"time"
)

// zadnje 3 znamenke JMBAG-a
const jmbag = 123

var (
	errNoData  = errors.New("no data")
	errTimeout = errors.New("timeout")
)

func sendData(numbers chan int) {
	num := []int{1, 2, 3, 4, 5, 1, 2, 3, 1}
	for _, v := range num {
		numbers <- v
	}
	close(numbers)
}

func main() {
	num := make(chan int, 1)
	go sendData(num)
	mostCommon, err := minFromChann(num)
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(mostCommon)
	}
}

func minFromChann(numbers chan int) (int, error) {
	smallest := math.MaxInt8
	nums := 0
	end := false

	for !end {

		select {
		case number, ok := <-numbers:
			if !ok && nums == 0 {
				return 0, errNoData
			}
			if !ok {
				end = true
				break
			}

			nums++
			if number < smallest {
				smallest = number
			}

		case <-time.After(1 * time.Second):
			return 0, errTimeout
		}
	}

	return smallest * jmbag, nil
}
