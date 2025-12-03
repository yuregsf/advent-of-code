import { print, solve, testInput } from '../lib';

function part1(input: string): number {
  const equations = input.split('\n').slice(0, -1)

  for(const equation of equations) {
    const [result, operandsEnc] = equation.split(": ");
    const operands = operandsEnc.split(" ")
  }

  print(equations)

  return 0;
}

testInput('input.test', part1, 3749)
