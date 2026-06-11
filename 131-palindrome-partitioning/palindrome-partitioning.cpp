class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    bool is_palindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(string& s, int i){
        if(i == s.size()){
            res.push_back(path);
            return;
        }

        for(int j = i; j < s.size(); j++){
            if(is_palindrome(s, i, j)){
                path.push_back(s.substr(i, j - i + 1));
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