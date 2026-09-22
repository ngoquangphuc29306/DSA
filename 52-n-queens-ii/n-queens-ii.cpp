#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int i, int& res, int n, vector<int>& c, vector<int>& d1, vector<int>& d2) {
        for (int j = 1; j <= n; j++) {
            if (!c[j] && !d1[i - j + n] && !d2[i + j - 1]) {
                c[j] = d1[i - j + n] = d2[i + j - 1] = 1;

                if (i == n) {
                    res++;
                } else {
                    backtrack(i + 1, res, n, c, d1, d2);
                }

                c[j] = d1[i - j + n] = d2[i + j - 1] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<int> c(2 * n, 0);
        vector<int> d1(2 * n, 0);
        vector<int> d2(2 * n, 0);
        int res = 0;
        
        backtrack(1, res, n, c, d1, d2);
        
        return res;
    }
};