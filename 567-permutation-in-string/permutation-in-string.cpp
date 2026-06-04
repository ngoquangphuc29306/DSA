class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> cnt;

        for (char c : s1)
            cnt[c]++;

        int l = 0;
        int n_letters = s1.size();

        for (int r = 0; r < s2.size(); r++) {
            int n = cnt[s2[r]];
            cnt[s2[r]]--;

            if (n > 0) {
                // Ký tự này đang cần thiết để tạo hoán vị của s1
                n_letters--;
            } else {
                while (cnt[s2[r]] < 0) {
                    cnt[s2[l]]++;

                    if (cnt[s2[l]] > 0) {
                        // Tránh trường hợp subfrequence
                        n_letters++;
                    }
                    l++;
                }
            }

            if (n_letters == 0)
                return true;
        }
        return false;
    }
};
// Time Complexity O(n), n = len(s1) + len(s2)
// Space Complexity O(26) = O(1)