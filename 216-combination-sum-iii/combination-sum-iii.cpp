class Solution {
public:
    vector<vector<int>> ret;
    vector<int>candidates{1,2,3,4,5,6,7,8,9};
    void backtrack(vector<int>& cur, int target, int k, int cur_i){
        if(target<0) return;
        if(target == 0 and cur.size() == k) {
            ret.push_back(cur);
            return;
        }
        for(int i=cur_i;i<candidates.size();i++){
            cur.push_back(candidates[i]);
            backtrack(cur, target-candidates[i], k, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>cur;
        backtrack(cur, n, k, 0);
        return ret;
    }
};