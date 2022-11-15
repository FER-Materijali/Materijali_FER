package triangles

type EquilateralTriangle struct{}

func (t *EquilateralTriangle) Name() string {
	return "equilateral triangle"
}

func (t *EquilateralTriangle) NumberOfSides() int {
	return 3
}

func (t *EquilateralTriangle) Type() string {
	return "triangle"
}

type RightTriangle struct{}

func (t *RightTriangle) Name() string {
	return "right triangle"
}

func (t *RightTriangle) NumberOfSides() int {
	return 3
}

func (t *RightTriangle) Type() string {
	return "triangle"
}
