class Solution {
public:
    vector<string> result;

    void backtrack(string& s, unordered_map<int, vector<char>>& mp, int start, string cur_string){
        if(start == s.size()){
            result.push_back(cur_string);
            return;
        }
        
        int n = s[start] - '0';
        int k = 3;
        if(n == 7 || n == 9) k = 4;

        for(int i = 0; i < k; i++){
            cur_string += mp[n][i];
            backtrack(s, mp, start + 1, cur_string);
            cur_string.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> mp;
        mp[2]={'a', 'b', 'c'};
        mp[3]={'d', 'e', 'f'};
        mp[4]={'g', 'h', 'i'};
        mp[5]={'j', 'k', 'l'};
        mp[6]={'m', 'n', 'o'};
        mp[7]={'p', 'q', 'r', 's'};
        mp[8]={'t', 'u', 'v'};
        mp[9]={'w', 'x', 'y', 'z'};
        backtrack(digits, mp, 0, "");
        return result;
    }
};