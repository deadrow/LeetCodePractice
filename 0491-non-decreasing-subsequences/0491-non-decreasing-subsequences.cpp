class Solution {
public:
    set<vector<int>> uniqueSets;
    void backtrack(vector<int>& nums, vector<int>cur, int cur_i)
    {
        if(cur.size() >= 2)
        {
            uniqueSets.insert(cur);
        }
                
        for(int i=cur_i;i<nums.size();i++)
        {
            if(cur.empty() || nums[i] >= cur.back())
                cur.push_back(nums[i]);
            backtrack(nums, cur, i+1);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>cur;
        backtrack(nums, cur, 0);
        
        vector<vector<int>>res(uniqueSets.begin(), uniqueSets.end());
        return res;
    }
};