class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < k; i++){
            // Duy truy dq giảm dần
            // dp.front là phần tử lớn nhất
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Thêm phần tử lớn nhất vào đáp án
        ans.push_back(nums[dq.front()]);

        for(int i = k; i < nums.size(); i++){
            if(!dq.empty() && i - dq.front() >= k){
                // Xóa phần tử đẫ ra khỏi cửa sổ
                dq.pop_front();
            }

            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
