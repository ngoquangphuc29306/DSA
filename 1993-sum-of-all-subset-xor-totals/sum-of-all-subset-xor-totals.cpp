class Solution {
int total_sum = 0;

void Try(vector<int> &nums, int i, int cur_xor){
    int n = nums.size();
    if(i == n){
        total_sum += cur_xor;
        return;
    }

    // Chọn ptu vào tập con
    Try(nums, i + 1, cur_xor ^ nums[i]);

    // Khoong chon
    Try(nums, i + 1, cur_xor);
}

public:
    int subsetXORSum(vector<int>& nums) {
        total_sum = 0;
        Try(nums, 0, 0);
        return total_sum;
    }
};