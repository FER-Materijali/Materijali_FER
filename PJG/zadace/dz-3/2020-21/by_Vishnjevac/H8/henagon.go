package main

type Henagon struct{}

func (d *Henagon) NumberOfSides() int {
	return 1
}

func (d *Henagon) Type() string {
	return "henagon"
}
