class Solution {
public:

    bool backtrack(int index, int cur_sum, int target, int k_left, vector<bool>& used, vector<int>& nums){
        if(k_left == 1) return true;

        if(cur_sum == target){
            return backtrack(0, 0, target, k_left - 1, used, nums);
        }

        for(int i = index; i < nums.size(); i++){
            if(used[i] || cur_sum + nums[i] > target) continue;

            used[i] = true;
            if(backtrack(i + 1, cur_sum + nums[i], target, k_left, used, nums)){
                return true;
            }
            used[i] = false;

            if(cur_sum == 0) break;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;

        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > target) return false;

        vector<bool> used(nums.size(), false);
        return backtrack(0, 0, target, k, used, nums);
    }
};