class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        int n = s.size(), m = t.size();

        unordered_map<char, int> cntT, cntS;

        for(auto c : t) cntT[c]++;

        int l = 0, ans = 1e9, j = 0;
        int cnt = 0;
        for(int r = 0; r < n; r++){
            cntS[s[r]]++;

            if(cntS[s[r]] <= cntT[s[r]]) cnt++;

            if(cnt == m){
                while((cntS[s[l]] > cntT[s[l]]) || cntT[s[l]] == 0){
                    if(cntS[s[l]] > cntT[s[l]]){
                        --cntS[s[l]];
                    }
                    l++;
                }
                int cur_len = r - l + 1;
                if(ans > cur_len){
                    ans = cur_len;
                    j = l;
                }
            }
        }
        string res = "";
        if(ans == 1e9) return "";
        else{
            for(int i = j; i <= ans + j - 1; i++){
                res += s[i];
            }
        }
        return res;
    }
};