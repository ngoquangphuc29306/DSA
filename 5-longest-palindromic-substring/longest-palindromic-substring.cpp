class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int maxLen = 0;
        int start = 0;

        for(int len = 1; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                //len = j - i + 1
                int j = len + i - 1;

                if(s[i] == s[j]){
                    if(len <= 3){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if(dp[i][j] && len > maxLen){
                    maxLen = len;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};