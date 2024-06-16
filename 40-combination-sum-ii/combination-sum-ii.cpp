class Solution {
public:
    vector<vector<int>> ret;
    void backtrack(vector<int>& candidates, vector<int>& cur, int target, int cur_i){
        if(target<0) return;
        if(target == 0) {
            ret.push_back(cur);
            return;
        }
        unordered_set<int>dict;
        for(int i=cur_i;i<candidates.size();i++){
            if(dict.count(candidates[i])) continue;
            dict.insert(candidates[i]);
            cur.push_back(candidates[i]);
            backtrack(candidates, cur, target-candidates[i], i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, cur, target, 0);
        return ret;
    }
};