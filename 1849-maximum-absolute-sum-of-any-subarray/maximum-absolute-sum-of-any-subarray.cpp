class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        int curMax=0;
        int curMin=0;
        for(int i=0;i<nums.size();i++){
            curMax = max(curMax+nums[i], nums[i]);
            curMin = min(curMin+nums[i], nums[i]);
            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);
        }
        return max(maxSum, -minSum);
    }
};