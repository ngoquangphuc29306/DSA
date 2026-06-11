class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> dp;

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
            if(dp[i][j]){
                path.push_back(s.substr(i, j - i + 1));
                backtrack(s, j + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.assign(n , vector<bool>(n, false));

        for(int len = 1; len <= n; len++){
            for(int start = 0; start + len - 1 < n; start++){
                int end = start + len - 1;

                if(s[start] == s[end]){
                    if(len <= 2){
                        dp[start][end] = true;
                    }
                    else{
                        dp[start][end] = dp[start + 1][end - 1];
                    }
                }
            }
        }
        backtrack(s, 0);
        return res;
    }
};