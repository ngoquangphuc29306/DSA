class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        multiset<int> se;
        
        for(int i = 0; i < k; i++){
            se.insert(nums[i]);
        }

        auto it = se.end();
        it--;

        vector<int> ans;
        ans.push_back(*it);
        int l = 0;
        for(int r = k; r < nums.size(); r++){
            se.insert(nums[r]);
            se.erase(se.find(nums[l]));
            
            l++;

            auto it = se.end();
            it--;
            ans.push_back(*it);
        }
        return ans;
    }
};
