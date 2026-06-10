class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    int used[1001][1001], check;

    void Try(int i, int j, int pos, string& s, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();

        if(check) return;

        if(s.size() == pos){
            check = 1;
            return;
        }

        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && board[x][y] == s[pos] && used[x][y] == 0){
                used[x][y] = 1;
                Try(x, y, pos + 1, s, board);
                used[x][y] = 0;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        check = 0;

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    used[i][j] = 1;
                    Try(i, j, 1, word, board);
                    used[i][j] = 0;
                }
            }
        }
        if(check) return true;
        else return false;
    }
};