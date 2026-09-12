class Solution {
private:
    void backtrack(vector<int>& comb, vector<vector<int>>& res, int i, int n, int k){
        if(comb.size() == k){
            res.push_back(comb);
            return;
        }

        for(int num = i; num <= n - (k - comb.size()) + 1; num++){
            comb.push_back(num);
            backtrack(comb, res, num + 1, n, k);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> res;
        backtrack(comb, res, 1, n, k);
        return res;
    }
};