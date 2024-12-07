import * as assert from 'assert';
import * as fs from 'node:fs';

function print(...vals: any) {
  console.log(...vals)
}

function testInput(path: string, funcToTest: (input: string) => number, expected: number) {
  const inputTest = fs.readFileSync(path).toString()
  assert.strictEqual(funcToTest(inputTest), expected)
  print("Success!")
}

function solve(path: string, func: (input: string) => number) {
  const input = fs.readFileSync(path).toString()
  console.log(func(input))
}

export {
  print,
  testInput,
  solve
}
