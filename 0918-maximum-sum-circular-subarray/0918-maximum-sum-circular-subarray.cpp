class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0;
        int bestMax = nums[0];
        int curMin = 0;
        int bestMin = nums[0];
        int totalSum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            curMax = max(curMax+nums[i], nums[i]);
            curMin = min(curMin+nums[i], nums[i]);
            
            bestMax = max(bestMax, curMax);
            bestMin = min(bestMin, curMin);
            
            totalSum += nums[i];
        }
        
        return bestMax < 0 ? bestMax : max(totalSum-bestMin, bestMax);
    }
};