class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    bool used[100];

    void backtrack(vector<int> a){
        if(path.size() == a.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < a.size(); i++){
            if(used[i]) continue;

            if(i > 0 && a[i] == a[i - 1] && !used[i - 1]){
                continue;
            }

            used[i] = true;
            path.push_back(a[i]);
            backtrack(a);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums);
        return res;
    }
};