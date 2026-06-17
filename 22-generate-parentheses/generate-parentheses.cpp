class Solution {
public:
    void generate(int n, vector<string>& ans, string sofar, int op, int cl){
        if(op > n)
            return;
        if(cl > op)
            return;
        if(cl == n && op == n){
            ans.push_back(sofar);
        }
        generate(n, ans, sofar + "(", op + 1, cl);
        generate(n, ans, sofar + ")", op, cl + 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, ans, "", 0, 0);
        return ans;
    }
};