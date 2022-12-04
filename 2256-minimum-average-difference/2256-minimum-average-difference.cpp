class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        vector<long>prefix(n);
        prefix[0] = nums[0];
        
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }
        
        int min_index = -1;
        int min_avg = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int cur = abs(prefix[i]/(i+1) - ((n-i-1) != 0 ? (prefix[n-1]-prefix[i])/(n-i-1) : 0));
            if(cur < min_avg)
            {
                min_avg = cur;
                min_index = i;
            }
        }
        
        return min_index;
    }
};