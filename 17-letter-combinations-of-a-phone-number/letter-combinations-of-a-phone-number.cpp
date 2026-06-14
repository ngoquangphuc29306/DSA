class Solution {
public:
    vector<string> mp = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> result;

    void backtrack(string& s, int start, string cur_string){
        if(start == s.size()){
            result.push_back(cur_string);
            return;
        }
        
        int n = s[start] - '0';

        for(auto digit: mp[n]){
            cur_string.push_back(digit);
            backtrack(s, start + 1, cur_string);
            cur_string.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        backtrack(digits, 0, "");
        return result;
    }
};