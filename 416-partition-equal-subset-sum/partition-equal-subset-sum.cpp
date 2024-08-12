class Solution {
public:
    vector<vector<int>>memo;
    bool dp(vector<int>& nums, int target, int i){
        if(target == 0) return true;
        if(target < 0 or i>= nums.size()) return false;
        if(memo[target][i] != -1) return memo[target][i];
        bool take = dp(nums, target-nums[i], i+1);
        bool leave = dp(nums, target, i+1);
        return memo[target][i] = take or leave;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total & 1) return false;
        memo.resize(total/2+1, vector<int>(nums.size()+1, -1));
        return dp(nums, total/2, 0);
    }
};