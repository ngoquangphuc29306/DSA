class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int m = (l + r) / 2;

            if(a[m] == target) return m;
            else if(a[l] <= a[m]){ // Từ l...m mảng sorted
                if(target >= a[l] && target <= a[m]){ // Kiểm tra có nằm trong l...r
                    r = m - 1;
                }
                else l = m + 1;
            }
            else{ // Từ m + 1..r đã sorted
                if(target >= a[m] && target <= a[r]){
                    l = m + 1;
                }
                else r = m - 1;
            }
        }
        return -1;
    }
};