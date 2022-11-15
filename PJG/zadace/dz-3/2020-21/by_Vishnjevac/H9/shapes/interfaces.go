package shapes

type GeometricShape interface {
	Type() string
	NumberOfSides() int
}
