// 2665. Counter II
// Difficulty: Easy
// https://leetcode.com/problems/counter-ii/
// Runtime: 57 ms (beats —)
// Memory: 54.8 MB (beats —)
// Submitted: 2026-08-08

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
  let presentCount = init;

  function increment() {
    return ++presentCount;
  }

  function decrement() {
      return --presentCount;
  }

  function reset() {
      return (presentCount = init);
  }

  return { increment, decrement, reset };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
