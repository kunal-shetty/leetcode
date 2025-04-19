// 1832. Check if the Sentence Is Pangram
// Difficulty: Easy
// https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// Runtime: 0 ms (beats —)
// Memory: 8.8 MB (beats —)
// Submitted: 2025-04-19

class Solution {
public:
    bool checkIfPangram(string sentence) {
    bool check = true;
	int arr[26] = { 0 };
	for(int i = 0; i < sentence.length(); i++)
		tolower(sentence[i]);
	vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i = 0; i < sentence.length(); i++){
		for(int j = 0; j < letters.size(); j++){
			if(sentence[i] == letters[j])
			arr[j] = 1;
		}
	}
	for(int i = 0; i < 26; i++){
		if(arr[i] == 0)
		return false;
	}
	return true;
    }
};
