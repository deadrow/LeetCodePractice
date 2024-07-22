class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double maxSum=nums[0];
        double curMax=nums[0];
        double curMin=nums[0];
        for(int i=1;i<nums.size();i++){
            int tempMax = max({(double)nums[i], curMax*nums[i], curMin*nums[i]});
            curMin = min({(double)nums[i], curMax*nums[i], curMin*nums[i]});
            curMax = tempMax;
            maxSum = max(maxSum, curMax);
        }
        return maxSum;
    }
};