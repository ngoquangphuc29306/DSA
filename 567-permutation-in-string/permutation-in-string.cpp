class Solution {
public:
    /*
        Ý tưởng:
            - Một hoán vị của s1 có độ dài là s1.size
            - Dùng cửa sổ kiểm tra đoạn con của s2 có độ dài là s1.size
    */
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> cnt1;
        unordered_map<char, int> cnt2;

        // Đếm ký tự của s1 và cửa sổ đầu tiên của s2
        for(int i = 0; i < s1.size(); i++){
            cnt1[s1[i]]++;
            cnt2[s2[i]]++;
        }

        if(cnt1 == cnt2) return true;

        int left = 0;
        for(int right = s1.size(); right < s2.size(); right++){
            // Thêm ký tự mới ở bên phải cửa sổ
            cnt2[s2[right]]++;

            // Loại bỏ ký tự cũ ở bên trái cửa sổ
            cnt2[s2[left]]--;

            if(cnt2[s2[left]] == 0){
                cnt2.erase(s2[left]);
            }

            left++;

            if(cnt1 == cnt2) return true;
        }
        return false;
    }
};
// Time Complexity O(n), n = len(s1) + 26 - (len(s1) - len(s2))
// Space Complexity O(26) = O(1)