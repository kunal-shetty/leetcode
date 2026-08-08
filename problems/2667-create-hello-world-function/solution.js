// 2667. Create Hello World Function
// Difficulty: Easy
// https://leetcode.com/problems/create-hello-world-function/
// Runtime: 37 ms (beats —)
// Memory: 53.8 MB (beats —)
// Submitted: 2026-08-08

/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
