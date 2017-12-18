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

func main() {
	generatorA := Generator{883, 16807, 2147483647}
	generatorB := Generator{879, 48271, 2147483647}

	answer := 0

	for i := 0; i < 5000000; i++ {
		generatorA.evolve()
		generatorB.evolve()

		fine := true

		for j := 0; j < 16; j++ {
			ga_bit := generatorA.Value & (1 << uint(j))
			gb_bit := generatorB.Value & (1 << uint(j))
			//fmt.Println(ga_bit, gb_bit)
			if ga_bit != gb_bit {
				fine = false
			}
		}

		if fine {
			answer += 1
		}
	}

	fmt.Println(answer)
}
