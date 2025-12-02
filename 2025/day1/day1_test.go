package day1_test

import (
	"2025/day1"
	"2025/tools"
	"testing"
)

func TestSolve1(t *testing.T) {
	name := "base_case_day1"
	day := 1
	part := 1
	filename := "input_test"
	want := 3

	t.Run(name, func(t *testing.T) {
		lines := tools.ReadInput(filename)
		got, gotErr := day1.Solve1(lines)
		if gotErr != nil {
			t.Errorf("Solve1() failed: %v", gotErr)
		}
		if got != want {
			t.Errorf("[%d/%d]: got: %d, expected: %d", day, part, got, want)
		}
	})
}

func TestSolve2(t *testing.T) {
	name := "base_case_day1"
	day := 1
	part := 2
	filename := "input_test"
	want := 6

	t.Run(name, func(t *testing.T) {
		lines := tools.ReadInput(filename)
		got, gotErr := day1.Solve2(lines)
		if gotErr != nil {
			t.Errorf("Solve2() failed: %v", gotErr)
		}
		if got != want {
			t.Errorf("[%d/%d]: got: %d, expected: %d", day, part, got, want)
		}
	})
}
