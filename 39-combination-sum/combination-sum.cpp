class Solution {
public:
    vector<int> x = vector<int>(50, 0);
    vector<int> path;
    vector<vector<int>> res;

    void Try(vector<int> a, int i, int start, int sum, int target){
        for(int j = start; j < a.size(); j++){
            x[i] = a[j];
            sum += a[j];
            if(sum == target){
                for(int l = 0; l <= i; l++){
                    path.push_back(x[l]);
                }
                res.push_back(path);
                path.clear();
            }
            else if(sum < target){
                Try(a, i + 1, j, sum, target);
            }
            sum -= a[j];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        Try(nums, 0, 0, 0, target);
        return res;
    }
};
