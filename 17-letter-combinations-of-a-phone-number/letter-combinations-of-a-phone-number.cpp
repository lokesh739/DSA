class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string current;
        vector<string> mapping = {
            "", "", "abc", "def",  // 0, 1, 2, 3
            "ghi", "jkl", "mno",   // 4, 5, 6
            "pqrs", "tuv", "wxyz"  // 7, 8, 9
        };

        backtrack(0, digits, mapping, current, result);
        return result;
    }

private:
    void backtrack(int index, const string& digits, const vector<string>& mapping,
                   string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);
            backtrack(index + 1, digits, mapping, current, result);
            current.pop_back();  // backtrack
        }
    }
};
