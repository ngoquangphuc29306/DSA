class Solution {
public:

    bool backtrack(int index, vector<int>& sides, vector<int>& nums, int target, int k){
        if (index == nums.size()){
            for(int i = 0; i < k; i++){
                if(sides[i] != target){
                    return false;
                }
            }
            return true;
        }

        for(int i = 0; i < k; i++){
            if(sides[i] + nums[index] <= target){
                sides[i] += nums[index];
                if(backtrack(index + 1, sides, nums, target, k)){
                    return true;
                }
                sides[i] -= nums[index];
            }

            if(sides[i] == 0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % k != 0) return false;

        vector<int> sides(k, 0);
        int target = sum / k;
        return backtrack(0, sides, nums, target, k);
    }
};