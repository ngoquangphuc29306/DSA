

class Solution {
public:
    vector<vector<string>> res;

    void backtrack(
        int n, 
        vector<int>& cot, 
        vector<int>& xuoi, 
        vector<int>& nguoc, 
        vector<string>& path, 
        int row){   

        if(row == n){
            res.push_back(path);
            return;
        }

        for(int col = 0; col < n; col++){

            if(!cot[col] && !xuoi[row - col + n] && !nguoc[row + col]){
                cot[col] = 1;
                xuoi[row - col + n] = 1;
                nguoc[row + col] = 1;

                path[row][col] = 'Q';
                
                backtrack(n, cot, xuoi, nguoc, path, row + 1);

                path[row][col] = '.';
                
                cot[col] = 0;
                xuoi[row - col + n] = 0;
                nguoc[row + col] = 0;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n , string(n, '.'));
        vector<int> cot(2 * n, 0);
        vector<int> nguoc(2 * n, 0);
        vector<int> xuoi(2 * n, 0);

        backtrack(n, cot, xuoi, nguoc, path, 0);

        return res;
    }
};