"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var assert = require("assert");
var fs = require("fs");
function parse(input) {
    var lines = input.split("\n");
    var left = [];
    var right = [];
    for (var _i = 0, lines_1 = lines; _i < lines_1.length; _i++) {
        var line = lines_1[_i];
        if (!line)
            continue;
        var _a = line.split(" "), a = _a[0], b = _a[1];
        left.push(+a);
        right.push(+b);
    }
    var parsed = new Array();
    parsed.push(left);
    parsed.push(right);
    return parsed;
}
function part1(input) {
    var _a = parse(input), left = _a[0], right = _a[1];
    left.sort();
    right.sort();
    return left.reduce(function (sum, curr, idx) { return sum + Math.abs(curr - right[idx]); }, 0);
}
function part2(input) {
    var _a = parse(input), left = _a[0], right = _a[1];
    var count = left.reduce(function (c, curr) { return c.set(curr, 0); }, new Map());
    right.forEach(function (curr) { return count.set(curr, count.get(curr) + 1); });
    return left.reduce(function (sum, curr) { return sum + curr * count.get(curr); }, 0);
}
var inputTest = fs.readFileSync('input.test').toString();
assert.strictEqual(part1(inputTest), 11);
var input = fs.readFileSync('input').toString();
console.log(part1(input));
assert.strictEqual(part2(inputTest), 31);
console.log(part2(input));
