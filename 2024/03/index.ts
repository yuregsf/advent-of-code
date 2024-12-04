import * as assert from 'assert';
import * as fs from 'fs';

function part1(input: string): number {
  const exp = /mul\((\d+),(\d+)\)/g;
  let sum = 0;

  const finds = Array.from(input.matchAll(exp))
  for (const find of finds) {
    const [_, a, b] = find
    sum += +a * +b
  }
  return sum;
}

function part2(input: string): number {
  const dosexp = /do\(\)/g;
  const dontsexp = /don't\(\)/g;
  const exp = /mul\((\d+),(\d+)\)/g;
  let sum = 0;

  const dos = Array.from(input.matchAll(dosexp))
  const donts = Array.from(input.matchAll(dontsexp))
  const mults = Array.from(input.matchAll(exp))

  const actions = [...dos, ...donts, ...mults]
  actions.sort((a, b) => a.index - b.index)

  let active = true;
  for (const action of actions) {
    const verb = action[0]

    if (verb == 'do()') {
      active = true
      continue
    }
    if (verb == 'don\'t()') {
      active = false
      continue
    }

    sum += active ? +action[1] * +action[2] : 0
  }

  return sum;
}

const inputTest = fs.readFileSync('input.test').toString()
assert.strictEqual(part1(inputTest), 161)
const input2Test = fs.readFileSync('input2.test').toString()
assert.strictEqual(part2(input2Test), 48)

const input = fs.readFileSync('input').toString()
console.log(part1(input))
console.log(part2(input))
