class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minProfit = INT_MAX;
        int res = 0;
        for(auto price : prices){
            minProfit = min(minProfit, price);
            res = max(res, price - minProfit);
        }
        return res;
    }
};
