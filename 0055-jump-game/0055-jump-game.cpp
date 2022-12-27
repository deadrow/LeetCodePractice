class Solution {
public:
    vector<int>memo;
    bool dp(vector<int>& nums, int i)
    {
        if(i >= nums.size()-1)
            return true;
        
        if(memo[i] != -1)
            return memo[i];
        
        int maxJump = min((int)nums.size()-1, nums[i]);
        for(int j=i+1;j<=i+maxJump;j++)
        {
            if(dp(nums, j))
                return memo[i] = true;
        }
        
        return memo[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        
        memo.resize(nums.size(), -1);
        return dp(nums, 0);
    }
    
    // Greedy from solutions
    bool canJump1(vector<int>& nums)
    {
        int n = (int)nums.size();
        
        int leftReachableIndex = n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(i+ nums[i] >= leftReachableIndex)
                leftReachableIndex = i;
        }

        return leftReachableIndex == 0;
    }
};