package day2

import (
	"2025/tools"
	"errors"
	"strconv"
	"strings"
)

func Solve1(lines []string) (uint64, error) {
	line := lines[0]
	ranges := strings.SplitSeq(line, ",")
	var count uint64 = 0

	for r := range ranges {
		n := strings.Split(r, "-")
		a, _ := strconv.ParseUint(n[0], 10, 0)
		b, _ := strconv.ParseUint(n[1], 10, 0)
		var i uint64
		for i = a; i <= b; i++ {
			t := strconv.FormatUint(i, 10)

			l := t[:len(t)/2]
			r := t[len(t)/2:]

			if l == r {
				count += i
			}
		}
	}

	return count, nil
}

func probe(t string) bool {
	p := t[:len(t)/2]

	if p == t[len(p):] {
		return true
	}

	return false
}

func Solve2(lines []string) (uint64, error) {
	line := lines[0]
	ranges := strings.SplitSeq(line, ",")
	var count uint64 = 0

	for r := range ranges {
		n := strings.Split(r, "-")
		a, _ := strconv.ParseUint(n[0], 10, 0)
		b, _ := strconv.ParseUint(n[1], 10, 0)

		for i := a; i <= b; i++ {
			s := strconv.FormatUint(i, 10)
			for probe_size := 1; probe_size <= len(s)/2+1; probe_size++ {
				found := false
				probe := s[:probe_size]
				if len(s)%probe_size != 0 {
					continue
				}
				for j := probe_size; j+probe_size <= len(s); j += probe_size {
					if probe != s[j:j+probe_size] {
						found = false
						break
					}
					found = true
				}

				if found {
					count += i
					break
				}
			}
		}
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

	s, err = Solve2(lines)
	if err != nil {
		return err
	}
	println(s)

	return nil
}
