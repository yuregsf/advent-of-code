package day3_test

import (
	"2025/day3"
	"2025/tools"
	"testing"
)

func TestSolve1(t *testing.T) {
	name := "base_case_day3_part1"
	day := 3
	part := 1
	filename := "input_test"
	want := 357

	t.Run(name, func(t *testing.T) {
		lines := tools.ReadInput(filename)
		got, gotErr := day3.Solve1(lines)
		if gotErr != nil {
			t.Errorf("Solve1() failed: %v", gotErr)
		}
		if got != want {
			t.Errorf("[%d/%d]: got: %d, expected: %d", day, part, got, want)
		}
	})
}

func TestSolve2(t *testing.T) {
	name := "base_case_day3_part2"
	day := 3
	part := 2
	filename := "input_test"
	want := uint64(3121910778619)

	t.Run(name, func(t *testing.T) {
		lines := tools.ReadInput(filename)
		got, gotErr := day3.Solve2(lines)
		if gotErr != nil {
			t.Errorf("Solve2() failed: %v", gotErr)
		}
		if got != want {
			t.Errorf("[%d/%d]: got: %d, expected: %d", day, part, got, want)
		}
	})
}
