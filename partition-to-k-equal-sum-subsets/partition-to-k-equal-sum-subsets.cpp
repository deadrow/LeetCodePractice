class Solution {
public:
    vector<int>memo;
    int targetSum = 0;
    bool dfs(vector<int>& nums, int& mask, int k, int target)
    {
        if(k == 1)
            return true;

        if(memo[mask] != -1)
            return memo[mask];
            
        if(target == 0)
            return dfs(nums, mask, k-1, targetSum);

        for(int i=0;i<nums.size();i++)
        {
            if(((mask >> i) & 1) == 1 || target-nums[i] < 0)
                continue;

            mask = mask | (1 << i);
            if(dfs(nums, mask, k, target-nums[i]))
                return memo[mask] = true;
            mask = mask ^ (1 << i);
        }

        return memo[mask] = false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum % k != 0)
            return false;

        targetSum = totalSum/k;
        
        int mask = 0;
        memo.resize(1<<n, -1);
        return dfs(nums, mask, k, targetSum);
    }
};