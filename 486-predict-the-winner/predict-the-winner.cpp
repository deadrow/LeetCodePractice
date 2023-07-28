class Solution {
public:
    int dp(vector<int>& nums, int left, int right, bool player1)
    {
        if(left > right)
            return 0;

        if(left == right)
        {
            return player1 ? nums[left] : -nums[left];
        }
        
        if(player1)
        {
            int takeFromLeft = nums[left] + dp(nums, left+1, right, false);
            int takeFromRight = nums[right] + dp(nums, left, right-1, false);
            return max(takeFromLeft, takeFromRight);
        }

        int takeFromLeft = dp(nums, left+1, right, true) - nums[left];
        int takeFromRight = dp(nums, left, right-1, true) - nums[right];
        return min(takeFromLeft, takeFromRight);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int res = dp(nums, 0, nums.size()-1, true);
        return res >= 0;
    }
};