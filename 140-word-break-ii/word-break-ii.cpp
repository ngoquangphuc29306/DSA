class Solution {
public:
    unordered_map<int, vector<string>> memo;
    unordered_set<string> dict;
    
    vector<string> dfs(string &s, int start){
        if(memo.count(start)){
            return memo[start];
        }

        vector<string> res;

        if(start == s.size()){
            res.push_back("");
            return res;
        }

        for(int end = start + 1; end <= s.size(); end++){
            string word = s.substr(start, end - start);
            
            if(!dict.count(word)){
                continue;
            }

            vector<string> suffix = dfs(s, end);

            for(auto sub: suffix){
                if(sub.empty()){
                    res.push_back(word);
                }
                else{
                    res.push_back(word + " " + sub);
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