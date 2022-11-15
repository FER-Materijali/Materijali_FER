package main

import (
	"fmt"

	"fergo.dev/H9/shapes"
	"fergo.dev/H9/shapes/digon"
	"fergo.dev/H9/shapes/dot"
	"fergo.dev/H9/shapes/henagon"
	"fergo.dev/H9/shapes/triangles"
)

func main() {
	shapes := []shapes.GeometricShape{
		&dot.Dot{},
		&henagon.Henagon{},
		&Octagon{},
		&digon.Digon{},
		&triangles.RightTriangle{},
		&triangles.RightTriangle{},
		&triangles.EquilateralTriangle{},
	}
	fmt.Println(countSides(shapes)) // 20
}
