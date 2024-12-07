import { testInput, solve } from '../lib'

type Rule = Map<number, {
  before: number[],
  after: number[]
}>

function filter(input: string) {
  const lines = input.split("\n").slice(0, -1);
  const rulesEnc = lines.slice(0, lines.indexOf(''))
  const updates = lines.slice(lines.indexOf('') + 1).map(s => s.split(",").map(a => +a))
  const rules: Rule = new Map();

  for (const rule of rulesEnc) {
    const [a, b] = rule.split("|")

    let aux = rules.get(+a)
    rules.set(+a, { ...aux ?? { before: [] }, after: [...(aux?.after ?? []), +b] })
  }

  let corrects = [];
  let wrongs = [];
  for (const update of updates) {
    let correct = true;
    for (const i in update) {
      const rule = rules.get(update[i])
      const left = update.slice(0, +i)

      if (left.find(x => rule?.after.includes(x))) {
        correct = !correct;
        break;
      }
    }
    if (correct) {
      corrects.push(update)
      continue;
    };

    wrongs.push(update)
  }
  return { wrongs, corrects, rules };
}


function sumMids(input: number[][]) {
  let sum = 0;
  for (const correct of input) {
    const mid = correct.length / 2
    sum += correct.slice(mid, mid + 1)[0];
  }

  return sum;
}


function part1(input: string): number {
  const { corrects } = filter(input);

  return sumMids(corrects);
}

function part2(input: string): number {
  const { wrongs, rules } = filter(input);

  for (const wrong of wrongs) {
    wrong.sort((a, b) => {
      const ruleA = rules.get(a)

      return ruleA?.after.includes(b) ? -1 : 1
    })
  }
  return sumMids(wrongs)
}

testInput('input.test', part1, 143)
testInput('input.test', part2, 123)
solve('input', part1)
solve('input', part2)
