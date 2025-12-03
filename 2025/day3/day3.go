package day3

import (
	"2025/tools"
	"errors"
	"math"
	"strconv"
	"strings"
)

func Solve1(lines []string) (int, error) {
	count := 0

	for _, line := range lines {
		numbersStr := strings.SplitSeq(line, "")
		var numbers []int

		for n := range numbersStr {
			number, err := strconv.Atoi(n)
			if err != nil {
				return 0, errors.New("Failed to parse number")
			}

			numbers = append(numbers, number)
		}

		numLen := len(numbers)
		sum := 0
		for i := 0; i < numLen-1; i++ {
			for j := i + 1; j < numLen; j++ {
				x := numbers[i]*10 + numbers[j]
				if x > sum {
					sum = x
				}
			}
		}

		count += sum
	}

	return count, nil
}

func depth_sum(arr []uint64, depth, idx int) uint64 {
	if depth == -1 {
		return 0
	}
	i := idx
	arrLen := len(arr)
	var biggest uint64 = 0
	largestIdx := 0
	for ; i < arrLen-depth; i++ {
		if arr[i] > biggest {
			biggest = arr[i]
			largestIdx = i
		}
	}

	return biggest*uint64(math.Pow10(depth)) + depth_sum(arr, depth-1, largestIdx+1)
}

func Solve2(lines []string) (uint64, error) {
	var count uint64 = 0

	for _, line := range lines {
		numbersStr := strings.SplitSeq(line, "")
		var numbers []uint64

		for n := range numbersStr {
			uNumber, err := strconv.ParseUint(n, 10, 0)
			if err != nil {
				return 0, errors.New("Failed to parse number")
			}
			number := uNumber
			numbers = append(numbers, number)
		}
		count += depth_sum(numbers, 11, 0)
	}

	return count, nil
}

func Solve(filename string) error {
	if filename == "" {
		return errors.New("Filename not provided\n")
	}
	lines := tools.ReadInput(filename)

	s, err := Solve1(lines)
	if err != nil {
		return err
	}
	println(s)

	s2, err := Solve2(lines)
	if err != nil {
		return err
	}
	println(s2)
	return nil
}
