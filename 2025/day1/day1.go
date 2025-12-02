package day1

import (
	"2025/tools"
	"errors"
	"strconv"
)

func Solve1(lines []string) (int, error) {
	curr := 50
	count := 0
	for _, line := range lines {
		direction := line[0]
		angle, errAtoi := strconv.Atoi(line[1:])
		if errAtoi != nil {
			return -1, errors.New("Error while converting int")
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
	return count, nil
}

func Solve2(lines []string) (int, error) {
	curr := 50
	count := 0
	for _, line := range lines {
		direction := line[0]
		angle, errAtoi := strconv.Atoi(line[1:])
		if errAtoi != nil {
			return -1, errors.New("Error while converting int")
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
	return count, nil
}

func Solve(filename string) error {
	if filename == "" {
		return errors.New("Filename not provided\n")
	}
	var lines = tools.ReadInput(filename)
	var errSolve error

	result1, errSolve := Solve1(lines)
	if errSolve != nil {
		return errSolve
	}
	println(result1)

	result2, errSolve := Solve2(lines)
	if errSolve != nil {
		return errSolve
	}
	println(result2)

	return nil
}
