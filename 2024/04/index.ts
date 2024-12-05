import * as assert from 'assert';
import * as fs from 'fs';

function getDiagonals(lines: string[]): string[] {
  const diagonals = []

  for (const line in lines) {
    for (const col in lines[line].split('')) {
      if (+line + 3 >= lines.length || +col + 3 >= lines[line].length) break;
      diagonals.push(`${lines[line][col]}${lines[+line + 1][+col + 1]}${lines[+line + 2][+col + 2]}${lines[+line + 3][+col + 3]}`)
    }

  }
  return diagonals
}

function countXMAS(lines: string[]) {
  let sum = 0;
  for (const line of lines) {
    sum += Array.from(line.matchAll(/XMAS/g)).length
    sum += Array.from(line.split('').reverse().join('').matchAll(/XMAS/g)).length
  }

  return sum;
}

function xmas(lines: string[]) {
  let coords: Array<number[]> = []
  let sum = 0;
  for (const line in lines) {
    for (const col in lines[line].split('')) {
      if (lines.at(+line)?.at(+col) == 'M' && lines.at(+line)?.at(+col + 2) == 'M') coords.push([+line, +col])
    }
  }

  for (const [y, x] of coords) {
    if (lines.at(y - 1)?.at(x + 1) === 'A') {
      if (lines.at(y - 2)?.at(x) === 'S' && lines.at(y - 2)?.at(x + 2) === 'S') {
        sum++;
      }
    }

    if (lines.at(y + 1)?.at(x + 1) === 'A') {
      if (lines.at(y + 2)?.at(x) === 'S' && lines.at(y + 2)?.at(x + 2) === 'S') {
        sum++;
      }

    }
  }
  return sum;
}

function part1(input: string): number {
  let sum = 0;
  let lines = input.split("\n").slice(0, -1)
  const columns = lines[0].split("").map(_ => "")

  let diagonals: string[] = []

  for (const line of lines) {
    for (const j in line.split('')) {
      columns[j] = columns[j].concat(line[j])
    }
  }

  diagonals = diagonals.concat(getDiagonals(lines))
  lines = lines.reverse()
  diagonals = diagonals.concat(getDiagonals(lines))

  sum += countXMAS(lines);
  sum += countXMAS(columns);
  sum += countXMAS(diagonals);

  return sum;
}

function part2(input: string): number {
  let sum = 0;
  let lines = input.split("\n").slice(0, -1)
  const columns = lines[0].split("").map(_ => "")

  for (const line of lines) {
    for (const j in line.split('')) {
      columns[j] = columns[j].concat(line[j])
    }
  }

  sum += xmas(lines)
  sum += xmas(columns)

  return sum;
}

const inputTest = fs.readFileSync('input.test').toString()
assert.strictEqual(part1(inputTest), 18)
const input2Test = fs.readFileSync('input.test').toString()
assert.strictEqual(part2(input2Test), 9)

const input = fs.readFileSync('input').toString()
console.log(part1(input))
console.log(part2(input))
