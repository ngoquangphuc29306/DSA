class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void Try(const vector<int>& a, int start, int target){
        if(target == 0){
            res.push_back(path);
            return;
        }

        if(target < 0) return;

        for(int j = start; j < a.size(); j++){
            if(j > start && a[j - 1] == a[j])
                continue;
            
            if(a[j] > target) break;
            
            path.push_back(a[j]);
            Try(a, j + 1, target - a[j]);
            // backtrack
            path.pop_back();
        }        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        Try(nums, 0, target);
        return res;
    }
};
