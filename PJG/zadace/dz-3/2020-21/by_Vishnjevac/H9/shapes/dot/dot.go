package dot

type Dot struct{}

func (d *Dot) Type() string {
	return "dot"
}

func (d *Dot) NumberOfSides() int {
	return 0
}
