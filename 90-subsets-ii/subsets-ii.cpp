class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void Try(vector<int> a, int start){
        res.push_back(path);

        for(int i = start; i < a.size(); i++){
            //Tránh trùng nhau
            if(i > start && a[i - 1] == a[i]){
                continue;
            }

            path.push_back(a[i]);
            Try(a, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Để các phần tử giống nhau đứng cạnh nhau
        // Dễ loại bỏ duplicate
        sort(nums.begin(), nums.end());
        Try(nums, 0);
        return res;
    }
};