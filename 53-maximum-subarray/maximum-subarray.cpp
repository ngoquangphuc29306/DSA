class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0], res = nums[0];

        for(int i = 1; i < n; i++){
            if(cur < 0) cur = 0;
            cur += nums[i];
            res = max(res, cur);
        }

        return res;
    }
};
