class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;

        long curSum = 0;
        int ret = 0;
        for(int j=0;j<n;j++)
        {
            curSum += nums[j];
            long target = nums[j];

            while((j-i+1)*target - curSum > k)
            {
                curSum -= nums[i];
                i++;
            }

            ret = max(ret, j-i+1);
        }

        return ret;
    }
};