class Solution {
public:
    vector<vector<int>> ret;
    
    void helper(vector<int>& cur, int cur_i, int k, int target)
    {
        if(cur.size() > k || target < 0)
            return;
        
        if(cur.size() == k && target == 0)
        {
            ret.push_back(cur);
            return;
        }
        
        for(int i=cur_i;i<=9;i++)
        {
            cur.push_back(i);
            helper(cur, i+1, k, target-i);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        helper(cur, 1, k, n);
        return ret;
    }
};