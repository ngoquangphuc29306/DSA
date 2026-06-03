class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> cnt;
        int res = 0;
        int maxFreq = 0;
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            cnt[s[r]]++;
            
            maxFreq = max(maxFreq, cnt[s[r]]);

            while((r - l + 1) - maxFreq > k){
                cnt[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};