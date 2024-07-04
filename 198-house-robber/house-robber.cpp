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
    int rob1(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dp(nums,0);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums[0];
        int prev_2 = nums[0];
        int prev_1 = max(nums[0],nums[1]);
        int cur = prev_1;
        for(int i=2;i<nums.size();i++){
            // dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
            cur = max(nums[i]+prev_2, prev_1);
            prev_2 = prev_1;
            prev_1 = cur;
        }
        return cur;
    }
};