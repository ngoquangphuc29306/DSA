class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];

        if(sum % 2 == 1) return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }

        for(int i = 1; i <= n; i++){
            for(int s = 1; s <= target; s++){
                // Không chon nums[i]
                dp[i][s] = dp[i - 1][s];

                // Chọn nums[i]
                if(s >= nums[i - 1]){
                    dp[i][s] = dp[i][s] || dp[i - 1][s - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};