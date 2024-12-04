import * as assert from 'assert';
import * as fs from 'fs';

function parse(input: string): Array<number[]> {
  const lines = input.split("\n").slice(0, -1)

  return lines.map(line => line.split(" ").map(n => +n));
}

function safe(report: number[]): boolean {
  let previous = report[0];
  let sign = report[1] - report[0];

  for (const current of report.slice(1)) {
    if ((sign > 0 && current < previous) || (sign < 0 && current > previous)) {
      return false
    }
    const diff = Math.abs(previous - current)
    if (diff < 1 || diff > 3) {
      return false
    }
    previous = current
  }

  return true;
}

function part1(input: string): number {
  const reports = parse(input);
  let sum = 0;

  for (const report of reports) {
    sum += safe(report) ? 1 : 0;
  }

  return sum;
}

function part2(input: string): number {
  const reports = parse(input);
  let sum = 0;

  for (const report of reports) {
    if (safe(report)) {
      sum++
      continue;
    }

    for (const i in report) {
      const aux = [...report];
      aux.splice(+i, 1);

      if (safe(aux)) {
        sum++;
        break;
      }
    }
  }

  return sum;
}

const inputTest = fs.readFileSync('input.test').toString()
assert.strictEqual(part1(inputTest), 2)

const input = fs.readFileSync('input').toString()
console.log(part1(input))

assert.strictEqual(part2(inputTest), 4)
console.log(part2(input))
