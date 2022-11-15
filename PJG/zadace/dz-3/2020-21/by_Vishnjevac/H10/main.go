package main

import (
	"fmt"
	"reflect"
	"unicode"
)

type Point struct {
	X       int
	Y       int
	private string
}

func main() {
	fmt.Println(fields(Point{})) // [X Y]
}
func fields(t interface{}) []string {
	values := reflect.ValueOf(t)
	output := make([]string, 0)

	for i := 0; i < values.NumField(); i++ {
		value := values.Type().Field(i).Name

		firstRune := rune(value[0])
		if unicode.IsUpper(firstRune) {
			output = append(output, value)
		}
	}
	return output
}
