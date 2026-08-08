// 2704. To Be Or Not To Be
// Difficulty: Easy
// https://leetcode.com/problems/to-be-or-not-to-be/
// Runtime: 50 ms (beats —)
// Memory: 52.6 MB (beats —)
// Submitted: 2026-08-08

var expect = function(val) {
    return {
        toBe: function(otherVal) {
            if (val === otherVal) return true;
            else throw new Error("Not Equal");
        },
        notToBe: function(otherVal) {
            if (val !== otherVal) return true;
            else throw new Error("Equal");
        }
    };
};
