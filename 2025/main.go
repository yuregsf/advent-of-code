package main

import (
	"2025/day1"
	"2025/day2"
)

func handle_err(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
	var err error
	err = day1.Solve("day1/input_1")
	handle_err(err)

	println("==============")
	err = day2.Solve("day2/input_2")
	handle_err(err)
}
