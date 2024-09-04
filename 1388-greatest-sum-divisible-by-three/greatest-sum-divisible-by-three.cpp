class Solution {
public:
    // MLE because of curSum
    // instead pass remainder
    // vector<vector<int>>memo;
    // int dp(vector<int>& nums, int curSum, int i){
    //     if(i>=nums.size()) return curSum % 3  ? 0 : curSum;
    //     if(memo[i][curSum] != -1) return memo[i][curSum];
    //     int take = dp(nums, curSum+nums[i], i+1);
    //     int leave = dp(nums, curSum, i+1);
    //     return memo[i][curSum]=max(take, leave);
    // }

    vector<vector<int>>memo;
    int dp(vector<int>& nums, int remainder, int i){
        if(i>=nums.size()) return remainder ? INT_MIN : 0;
        if(memo[i][remainder] != -1) return memo[i][remainder];
        int take = nums[i]+dp(nums, (remainder+nums[i])%3, i+1);
        int leave = dp(nums, remainder, i+1);
        return memo[i][remainder]=max(take, leave);
    }
    int maxSumDivThree(vector<int>& nums) {
        memo.resize(nums.size(), vector<int>(3, -1));
        return dp(nums, 0, 0);
    }
};