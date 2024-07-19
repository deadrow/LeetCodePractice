class Solution {
public:
    vector<vector<int>>memo;
    bool dp(vector<int>& nums, int i, int target){
        if(i>=nums.size()) return false;
        if(target == 0) return true;
        if(memo[i][target] != -1) return memo[i][target];
        bool take = false;
        if(target-nums[i] >= 0)
            take = dp(nums, i+1, target-nums[i]);
            
        bool leave = dp(nums,i+1, target);
        return memo[i][target] = take or leave;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum % 2 != 0) return false;
        memo.resize(nums.size()+1, vector<int>(sum/2+1, -1));
        return dp(nums, 0, sum/2);
    }
};