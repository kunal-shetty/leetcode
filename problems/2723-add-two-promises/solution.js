// 2723. Add Two Promises
// Difficulty: Easy
// https://leetcode.com/problems/add-two-promises/
// Runtime: 53 ms (beats —)
// Memory: 54.5 MB (beats —)
// Submitted: 2026-05-28

/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    val1 = await promise1
    val2 = await promise2
    return val1 + val2
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
