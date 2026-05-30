class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l < r){
            int m = (l + r) / 2;
            if(nums[m] > nums[r]){
                // Nằm phía bên trái
                l = m + 1;
            }
            else if(nums[m] < nums[r]){
                r = m;
            }
        }
        return nums[l];
    }
};