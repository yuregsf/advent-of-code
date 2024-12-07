import { testInput, print, solve } from "../lib"

function changeDirection(direction: number[]): number[] {
  const [x, y] = direction;

  const newX = y > 0 ? 1 : y < 0 ? -1 : 0;
  const newY = x < 0 ? 1 : x > 0 ? -1 : 0;

  return [newX, newY];
}

function stringifyMap(map: string[][]) {
  const aux = []
  for (const line of map) {
    aux.push(line.join(''))
  }
  return aux.join('\n')
}

function printMap(map: string[][]) {
  print(stringifyMap(map))
}

function part1(input: string): number {
  const lines = input.split("\n").slice(0, -1)
  const map = lines.map(line => [...line.split('')])
  let pos: number[] = []

  for (const x in map) {
    for (const y in map[x]) {
      if (map[x][y] == '^') {
        pos = [+x, +y]
        break;
      }
    }
    if (pos.length > 0) break
  }

  let direction = [-1, 0];

  for (let x = pos[0], y = pos[1]; x < map.length && y < map[x].length && x >= 0 && y >= 0; x += direction[0], y += direction[1]) {
    if (map[x][y] == '#') {
      x -= direction[0]
      y -= direction[1]
      direction = changeDirection(direction);
      continue
    }
    map[x][y] = 'X'
  }
  let sum = 0;
  const mapString = stringifyMap(map);

  for (const c of mapString) {
    sum += c == 'X' ? 1 : 0;
  }

  return sum;
}

function cleanPath(map: string[][]): void {
  for (let i in map) {
    for (let j in map[i]) {
      if (map[i][j] == 'X') map[i][j] = '.'
    }
  }
}

function part2(input: string): number {
  const lines = input.split("\n").slice(0, -1)
  const map = lines.map(line => [...line.split('')])
  let pos: number[] = []

  for (const x in map) {
    for (const y in map[x]) {
      if (map[x][y] == '^') {
        pos = [+x, +y]
        break;
      }
    }
    if (pos.length > 0) break
  }

  let direction = [-1, 0];

  for (let x = pos[0], y = pos[1]; x < map.length && y < map[x].length && x >= 0 && y >= 0; x += direction[0], y += direction[1]) {
    if (map[x][y] == '#') {
      x -= direction[0]
      y -= direction[1]
      direction = changeDirection(direction);
      continue
    }
    map[x][y] = 'X'
  }

  let sum = 0;
  const width = map.length
  const height = map[0].length
  for (let i = 0; i < map.length; ++i) {
    for (let j = 0; j < map[i].length; ++j) {
      if (map[i][j] != 'X') continue;

      let auxMap = map.map(a => [...a])
      direction = [-1, 0];
      auxMap[i][j] = '0'
      cleanPath(auxMap)
      let checked = false;

      for (let x = pos[0], y = pos[1]; x < width && y < height && x >= 0 && y >= 0; x += direction[0], y += direction[1]) {

        if (auxMap[x][y] == '0') {
          checked = true;
          auxMap[x][y] = '1';
          x -= direction[0];
          y -= direction[1];
          direction = changeDirection(direction);
          continue
        }
        if (auxMap[x][y] == '#') {
          if (checked) {
            auxMap[x][y] = '1'
          }
          x -= direction[0]
          y -= direction[1]
          direction = changeDirection(direction);
          continue
        }
        if (auxMap[x][y] == '1') {
          auxMap[x][y] = '2'
          x -= direction[0]
          y -= direction[1]
          direction = changeDirection(direction);
          continue
        }
        if (auxMap[x][y] == '2') {
          auxMap[x][y] = '3'
          x -= direction[0]
          y -= direction[1]
          direction = changeDirection(direction);
          continue
        }
        if (auxMap[x][y] == '3') {
          sum++;
          break;
        }
        auxMap[x][y] = 'X'
      }
    }
  }

  return sum;
}

testInput('input.test', part1, 41)
solve('input', part1)
testInput('input.test', part2, 6)
solve('input', part2)
