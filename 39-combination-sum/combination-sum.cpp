class Solution {
public:
    vector<vector<int>> ret;
    void backtrack(vector<int>& candidates, vector<int> cur, int target, int cur_i){
        if(target<0) return;
        if(target == 0) {
            ret.push_back(cur);
            return;
        }
        for(int i=cur_i;i<candidates.size();i++){
            cur.push_back(candidates[i]);
            backtrack(candidates, cur, target-candidates[i],i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        backtrack(candidates, cur, target, 0);
        return ret;
    }
};