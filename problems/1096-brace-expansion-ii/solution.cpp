// 1096. Brace Expansion II
// Difficulty: Hard
// https://leetcode.com/problems/brace-expansion-ii/
// Runtime: 11 ms (beats —)
// Memory: 17.9 MB (beats —)
// Submitted: 2026-09-25

class Solution {
    string s;
    int i = 0;

    set<string> product(const set<string> A, const set<string> B) {
        set<string> res;
        for (auto a : A) for (auto b : B) res.insert(a + b);
        return res;
    }

    set<string> unite(const set<string> A, const set<string> B) {
        set<string> res = A;
        res.insert(B.begin(), B.end());
        return res;
    }

    set<string> parseExpression() {
        set<string> res = parseTerm();
        while (i < s.size() && s[i] == ',') i++, res = unite(res, parseTerm());
        return res;
    }

    set<string> parseTerm() {
        set<string> res = parseItem();
        while (i < s.size() && (isalpha(s[i]) || s[i] == '{'))
            res = product(res, parseItem());
        return res;
    }

    set<string> parseItem() {
        if (s[i] == '{') {
            i++;
            set<string> res = parseExpression();
            i++;
            return res;
        }
        return {string(1, s[i++])};
    }

public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        set<string> result = parseExpression();
        return vector<string>(result.begin(), result.end());
    }
};
