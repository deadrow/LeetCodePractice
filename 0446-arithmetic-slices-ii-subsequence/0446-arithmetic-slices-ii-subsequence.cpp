class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ret = 0;
        vector<map<long,int>> dp(nums.size());
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                long diff = (long)nums[i]-(long)nums[j];
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += cnt+1;
                ret += cnt;
            }
        }
        
        return ret;
    }
};