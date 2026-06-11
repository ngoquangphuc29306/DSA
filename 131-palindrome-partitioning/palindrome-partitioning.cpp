class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    bool is_palindrome(string s){
        string t = s;
        reverse(t.begin(), t.end());
        return t == s;
    }

    void backtrack(string& s, int i){
        if(i == s.size()){
            res.push_back(path);
            return;
        }

        for(int j = i; j < s.size(); j++){
            string substring = s.substr(i, j - i + 1);

            if(is_palindrome(substring)){
                path.push_back(substring);
                backtrack(s, j + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};