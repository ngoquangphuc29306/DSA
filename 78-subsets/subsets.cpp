class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void Try(vector<int>& nums, int start){
        res.push_back(path);

        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            Try(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        Try(nums, 0);
        return res;
    }
};
