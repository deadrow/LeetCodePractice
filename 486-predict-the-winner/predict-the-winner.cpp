class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return 0;
            
        if(left == right)
            nums[left];
        
        if(memo[left][right] != -1)
            return memo[left][right];

        int takeFromLeft = nums[left] - dp(nums, left+1, right);
        int takeFromRight = nums[right] - dp(nums, left, right-1);
        return memo[left][right] = max(takeFromLeft, takeFromRight);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n+1, vector<int>(n+1,-1));
        int res = dp(nums, 0, n-1);
        return res >= 0;
    }
};