package day2_test

import (
	"2025/day2"
	"2025/tools"
	"testing"
)

func TestSolve1(t *testing.T) {
	name := "base_case_day2_part1"
	day := 2
	part := 1
	filename := "input_test"
	var want uint64 = 1227775554

	t.Run(name, func(t *testing.T) {
		lines := tools.ReadInput(filename)
		got, gotErr := day2.Solve1(lines)
		if gotErr != nil {
			t.Errorf("Solve1() failed: %v", gotErr)
		}
		if got != want {
			t.Errorf("[%d/%d]: got: %d, expected: %d", day, part, got, want)
		}
	})
}

func TestSolve2(t *testing.T) {
	name := "base_case_day2_part2"
	day := 1
	part := 2
	filename := "input_test"
	var want uint64 = 4174379265

	t.Run(name, func(t *testing.T) {
		lines := tools.ReadInput(filename)
		got, gotErr := day2.Solve2(lines)
		if gotErr != nil {
			t.Errorf("Solve2() failed: %v", gotErr)
		}
		if got != want {
			t.Errorf("[%d/%d]: got: %d, expected: %d", day, part, got, want)
		}
	})
}
