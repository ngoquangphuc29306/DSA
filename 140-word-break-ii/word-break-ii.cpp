class Solution {
public:
    unordered_map<int, vector<string>> memo;
    unordered_set<string> dict;
    
    vector<string> dfs(string &s, int start){
        if(memo.count(start)){
            return memo[start];
        }

        if(start == s.size()){
            return {""};
        }

        vector<string> res;
        for(int end = start + 1; end <= s.size(); end++){
            string word = s.substr(start, end - start);
            if(dict.count(word)){
                vector<string> sub_res = dfs(s, end);
                for(auto sub: sub_res){
                    res.push_back(word + (sub.empty() ? "": " ") + sub);
                }
            }
        }
        return memo[start] = res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo.clear();
        return dfs(s, 0);
    }
};