package main

import (
	"fmt"
	"strings"
)

func main() {
	shapes := []GeometricShape{
		&Dot{},
		&Henagon{},
		&Digon{},
		&RightTriangle{},
		&RightTriangle{},
		&EquilateralTriangle{},
	}
	fmt.Println(countTriangles(shapes)) // 3
	fmt.Println(countPolygons(shapes))  // 5
}

func countTriangles(shapes []GeometricShape) int {
	counter := 0
	for _, shape := range shapes {
		if strings.Contains(shape.Type(), "triangle") {
			counter++
		}
	}
	return counter
}

func countPolygons(shapes []GeometricShape) int {
	counter := 0
	for _, shape := range shapes {
		if strings.Contains(shape.Type(), "triangle") || strings.Contains(shape.Type(), "gon") {
			counter++
		}
	}
	return counter
}
