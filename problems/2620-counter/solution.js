// 2620. Counter
// Difficulty: Easy
// https://leetcode.com/problems/counter/
// Runtime: 44 ms (beats —)
// Memory: 53.1 MB (beats —)
// Submitted: 2026-08-08

/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function (n) {
    return function () {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
