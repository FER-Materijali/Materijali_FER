package main

import "fergo.dev/H9/shapes"

type Octagon struct{}

func (d *Octagon) Type() string {
	return "octagon"
}

func (d *Octagon) NumberOfSides() int {
	return 8
}

func countSides(shapes []shapes.GeometricShape) int {
	counter := 0
	for _, shape := range shapes {
		counter += shape.NumberOfSides()
	}
	return counter
}
