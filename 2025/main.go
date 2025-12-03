package main

import (
	"2025/day3"
)

func handle_err(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
	var err error
	err = day3.Solve("day3/input_3")
	handle_err(err)
}
