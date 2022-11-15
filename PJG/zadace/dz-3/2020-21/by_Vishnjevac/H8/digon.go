package main

type Digon struct{}

func (d *Digon) NumberOfSides() int {
	return 2
}

func (d *Digon) Type() string {
	return "digon"
}
