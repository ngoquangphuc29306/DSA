class Solution {
public:
    bool backtrack(int index, vector<int>& matchsticks, vector<int>& sides, int target){
        if(index == matchsticks.size()){
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }

        for(int i = 0; i < 4; i++){
            if(sides[i] + matchsticks[index] <= target){
                sides[i] += matchsticks[index];
                if(backtrack(index + 1, matchsticks, sides, target)){
                    return true;
                }
                sides[i] -= matchsticks[index];
            }
            if(sides[i] == 0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sort(matchsticks.rbegin(), matchsticks.rend());
        for(int i = 0; i < matchsticks.size(); i++){
            sum += matchsticks[i];
        }
        if(sum % 4 != 0){
            return false;
        }
        else{
            vector<int> sides(4, 0);
            int target = sum / 4;
            return backtrack(0, matchsticks, sides, target);
        }
    }
};