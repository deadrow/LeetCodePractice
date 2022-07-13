class Solution {
public:
    int targetSum;
    unordered_map<int, bool> memo;
    bool dfs(vector<int>& nums, int k, int cur_i, int& mask, int target)
    {
        if(k == 1)
            return true;

        if(memo.find(mask) != memo.end())
            return memo[mask];
        
        if(target == 0)
            return memo[mask] = dfs(nums, k-1, 0, mask, targetSum);

        for(int i=cur_i;i< nums.size();i++)
        {
            if(target - nums[i] < 0)
                continue;
            
            if(((mask >> i) & 1) == 0)
            {
                mask = (mask | (1 << i));
                if(dfs(nums, k, i+1, mask, target - nums[i]))
                    return true;
                mask = (mask ^ (1 << i));
            }
        }
        
        return memo[mask] = false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(totalSum % k != 0)
            return false;
        
        targetSum = totalSum/k;
        
        sort(nums.begin(), nums.end(), greater<>());
        
        int mask = 0;
        
        return dfs(nums, k, 0, mask, targetSum);
    }
};