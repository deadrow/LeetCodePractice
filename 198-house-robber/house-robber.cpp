class Solution {
public:
    vector<int>memo;
    int dp(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int take = nums[i] + dp(nums, i+2);
        int leave = dp(nums, i+1);
        return memo[i]= max(take, leave);
    }
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dp(nums,0);
    }
};