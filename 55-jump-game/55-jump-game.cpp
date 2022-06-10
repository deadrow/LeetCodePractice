class Solution {
public:
    vector<int>memo;
    bool dp(vector<int>& nums, int cur_i, int n)
    {
        if(cur_i >= n)
            return true;
        
        if(memo[cur_i] !=-1)
            return memo[cur_i];
        
        int farthest = min(cur_i+nums[cur_i], n);
        for(int pos=cur_i+1;pos<=farthest;pos++)
        {
            if(dp(nums, pos, n))
                return memo[cur_i] = true;
        }
        
        return memo[cur_i] = false;
    }
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1)
            return true;
        
        memo.resize(n,-1);
        return dp(nums, 0, n-1);
    }
};