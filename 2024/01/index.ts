import * as assert from 'assert';
import * as fs from 'fs';

function parse(input: string): Array<number[]> {
  const lines = input.split("\n")

  const left: number[] = [];
  const right: number[] = [];

  for (const line of lines) {
    if (!line) continue

    const [a, b] = line.split(" ")

    left.push(+a)
    right.push(+b)
  }

  const parsed: Array<number[]> = new Array();
  parsed.push(left);
  parsed.push(right);

  return parsed;
}

function part1(input: string): number {
  const [left, right] = parse(input);

  left.sort()
  right.sort()

  return left.reduce((sum, curr, idx) => sum + Math.abs(curr - right[idx]), 0);
}

function part2(input: string): number {
  const [left, right] = parse(input);

  const count = left.reduce((c, curr) => c.set(curr, 0), new Map())

  right.forEach(curr => count.set(curr, count.get(curr)+1));

  return left.reduce((sum, curr) => sum + curr * count.get(curr), 0);
}

const inputTest = fs.readFileSync('input.test').toString()
assert.strictEqual(part1(inputTest), 11)

const input = fs.readFileSync('input').toString()
console.log(part1(input))

assert.strictEqual(part2(inputTest), 31)
console.log(part2(input))
