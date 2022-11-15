package main

type GeometricShape interface {
	Type() string
}

type Polygon interface {
	NumberOfSides() int
}

type Triangle interface {
	Name() string
}
