import * as assert from 'assert';
import * as fs from 'node:fs';

export default {
  print(...vals: unknown[]) {
    console.log(vals)
  },
  testInput(path: string, funcToTest: (input: string) => number, expected: number) {
    const inputTest = fs.readFileSync(path).toString()
    assert.strictEqual(funcToTest(inputTest), expected)
  },
  solve(path: string, func: (input: string) => number) {
    const input = fs.readFileSync(path).toString()
    console.log(func(input))
  }
}
