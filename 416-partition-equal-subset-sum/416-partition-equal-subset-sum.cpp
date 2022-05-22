class Solution {
public:
    vector<vector<int>>memo;
    bool dp(vector<int>& nums, int i, int target)
    {
        if(target == 0)
            return true;

        if(i < 0)
            return false;

        if(memo[i][target] != -1)
            return memo[i][target] == 1;

        if(nums[i] <= target)
        {
            bool take = dp(nums, i-1, target - nums[i]);
            bool leave = dp(nums, i-1, target);
            return memo[i][target] = (take || leave);
        }

        // weg
        return memo[i][target] = dp(nums, i-1, target);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum % 2 != 0)
            return false;
        
        int target = sum/2;
        memo.resize(n+1, vector<int>(target+1, -1));
        return dp(nums, n-1, target);
    }
};