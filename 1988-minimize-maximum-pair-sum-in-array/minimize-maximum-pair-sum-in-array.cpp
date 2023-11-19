class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int minSum = 0;
        for(int i=0;i<n;i++)
        {
            minSum = max(minSum, nums[i] + nums[n-i-1]);
        }

        return minSum;
    }
};