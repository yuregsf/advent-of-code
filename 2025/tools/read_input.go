package tools

import (
	"os"
	"path"
	"strings"
)

func ReadInput(filename string) []string {
	dir, _ := os.Getwd()
	f := path.Join(dir, filename)
	dat, err := os.ReadFile(f)
	if err != nil {
		panic("Error while reading input\n")
	}

	input := string(dat)
	input = strings.TrimSpace(input)

	lines := strings.Split(input, "\n")

	return lines
}
