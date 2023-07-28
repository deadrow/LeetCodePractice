class Solution {
public:
    vector<vector<vector<int>>>memo;
    int dp(vector<int>& nums, int left, int right, bool player1)
    {
        if(left > right)
            return 0;

        if(left == right)
        {
            return player1 ? nums[left] : -nums[left];
        }
        
        if(memo[left][right][player1] != -1)
            return memo[left][right][player1];

        if(player1)
        {
            int takeFromLeft = nums[left] + dp(nums, left+1, right, false);
            int takeFromRight = nums[right] + dp(nums, left, right-1, false);
            return memo[left][right][player1] = max(takeFromLeft, takeFromRight);
        }

        int takeFromLeft = dp(nums, left+1, right, true) - nums[left];
        int takeFromRight = dp(nums, left, right-1, true) - nums[right];
        return memo[left][right][player1] = min(takeFromLeft, takeFromRight);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, vector<vector<int>>(n, vector<int>(2,-1)));
        int res = dp(nums, 0, nums.size()-1, true);
        return res >= 0;
    }
};