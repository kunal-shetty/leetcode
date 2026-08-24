// 2703. Return Length of Arguments Passed
// Difficulty: Easy
// https://leetcode.com/problems/return-length-of-arguments-passed/
// Runtime: 39 ms (beats —)
// Memory: 53.6 MB (beats —)
// Submitted: 2026-08-24

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return args.length
};

/**
 * argumentsLength(1, 2, 3); // 3
 */
