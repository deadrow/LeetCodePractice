class Solution {
public:
    vector<int>memo;
    int dfs(int mask, vector<int>& nums, int cur_i)
    {
        if(cur_i*2 == nums.size())
            return 0;

        if(memo[mask] != -1)
            return memo[mask];

        int curMax = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(((mask >> i) & 1) == 1 or ((mask >> j) & 1) == 1)
                    continue;
                
                mask = (mask | (1 << i) | (1 << j));
                curMax = max(curMax, (cur_i+1)*gcd(nums[i], nums[j]) + dfs(mask, nums, cur_i+1));
                mask = (mask ^ (1 << i) ^ (1 << j));
            }
        }

        return memo[mask] = curMax;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();

        memo.resize(1<<n, -1);
        return dfs(0, nums, 0);
    }
};