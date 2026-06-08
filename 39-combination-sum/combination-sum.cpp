class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void Try(vector<int> a, int start, int target){
        if(target == 0){
            res.push_back(path);
            return;
        }

        if(target < 0) return;

        for(int j = start; j < a.size(); j++){
            path.push_back(a[j]);
            Try(a, j, target - a[j]);
            path.pop_back();
        }        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        Try(nums, 0, target);
        return res;
    }
};
