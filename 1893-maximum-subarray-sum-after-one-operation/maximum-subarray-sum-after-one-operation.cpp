class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int curSum=nums[0];
        int squaredSum=nums[0]*nums[0];
        int maxSum=max(curSum, squaredSum);
        for(int i=1;i<nums.size();i++){
            squaredSum = max({curSum + nums[i]*nums[i], nums[i]*nums[i], squaredSum+nums[i]});
            curSum = max(curSum+nums[i], nums[i]);
            maxSum = max({maxSum, squaredSum, curSum});
        }
        return maxSum;
    }
};