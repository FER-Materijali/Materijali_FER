package main

type Dot struct{}

func (d *Dot) Type() string {
	return "dot"
}
