class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int>& nums, vector<int>&cur, int cur_i)
    {
        if(cur.size() > 1)
            res.push_back(cur);
                
        set<int> curNums;
        for(int i=cur_i;i<nums.size();i++)
        {
            if(curNums.find(nums[i]) != curNums.end())
                continue;
            
            if(cur.empty() || nums[i] >= cur.back())
            {
                curNums.insert(nums[i]);
                cur.push_back(nums[i]);
                backtrack(nums, cur, i+1);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>cur;
        backtrack(nums, cur, 0);
        
        // vector<vector<int>>res(uniqueSets.begin(), uniqueSets.end());
        return res;
    }
};