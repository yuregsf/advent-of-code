package main

import (
	"os"
	"strconv"
	"strings"
)

func solve_1(lines []string) {
	curr := 50
	count := 0
	for _, line := range lines {
		direction := line[0]
		angle, errAtoi := strconv.Atoi(line[1:])
		if errAtoi != nil {
			panic("Error while converting int")
		}

		if direction == 'L' {
			curr = (curr - angle) % 100
		} else {
			curr = (curr + angle) % 100
		}

		if curr == 0 {
			count++
		}
	}

	println(count)
}

func solve_2(lines []string) {
	curr := 50
	count := 0
	for _, line := range lines {
		direction := line[0]
		angle, errAtoi := strconv.Atoi(line[1:])
		if errAtoi != nil {
			panic("Error while converting int")
		}

		for angle > 0 {
			angle--
			if direction == 'L' {
				curr = (curr - 1) % 100
			} else {
				curr = (curr + 1) % 100
			}
			if curr == 0 {
				count++
			}
		}
	}
	println(count)
}

func main() {
	path := "input_1"
	dat, err := os.ReadFile(path)
	if err != nil {
		panic("Error while reading input\n")
	}

	input := string(dat)
	input = strings.TrimSpace(input)
	lines := strings.Split(input, "\n")

	solve_1(lines)
	solve_2(lines)
}
