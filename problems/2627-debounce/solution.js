// 2627. Debounce
// Difficulty: Medium
// https://leetcode.com/problems/debounce/
// Runtime: 48 ms (beats —)
// Memory: 54.5 MB (beats —)
// Submitted: 2026-06-12

/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timer;
    return function(...args) {
        clearTimeout(timer);
        timer = setTimeout(() => fn(...args), t);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
