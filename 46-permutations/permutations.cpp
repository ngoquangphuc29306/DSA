class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    bool used[10];

    void Try(vector<int> a){
        if(path.size() == a.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < a.size(); i++){
            if(!used[i]){
                used[i] = true;
                path.push_back(a[i]);

                Try(a);

                used[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        Try(nums);
        return res;
    }
};
