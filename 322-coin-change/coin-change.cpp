class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);

        for(int i = 1; i <= amount; i++){
            dp[i] = 1e9;
            for(int j = 0; j < n; j++){
                if(i >= coins[j] && dp[i - coins[j]] != 1e9){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if(dp[amount] == 1e9) return -1;
        return dp[amount];
    }
};