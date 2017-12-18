package main

import (
	"fmt"
)

type Generator struct {
	Value  int64
	Factor int64
	Mod    int64
}

func (g *Generator) evolve() {
	g.Value = (g.Value * g.Factor) % g.Mod
}

func isFine(a int64, b int64) bool {
	fine := true

	for j := 0; j < 16; j++ {
		ga_bit := a & (1 << uint(j))
		gb_bit := b & (1 << uint(j))

		if ga_bit != gb_bit {
			fine = false
		}
	}

	if fine {
		return true
	} else {
		return false
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	generatorA := Generator{883, 16807, 2147483647}
	generatorB := Generator{879, 48271, 2147483647}

	answer := 0

	validA := make([]int64, 0)
	validB := make([]int64, 0)

	for i := 0; i < 50000000; i++ {
		generatorA.evolve()
		generatorB.evolve()

		if generatorA.Value%4 == 0 {
			validA = append(validA, generatorA.Value)
		}
		if generatorB.Value%8 == 0 {
			validB = append(validB, generatorB.Value)
		}

	}

	for i := 0; i < 5000000; i++ {
		if isFine(validA[i], validB[i]) {
			answer += 1
		}
	}

	fmt.Println(answer)
}
