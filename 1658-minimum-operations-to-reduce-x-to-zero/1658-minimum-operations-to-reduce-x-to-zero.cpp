class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total-x;
        if(target < 0)
            return -1;
        
        int i=0;
        int sum = 0;
        int maxLen = INT_MIN;
        
        for(int j=0;j<n;j++)
        {
            sum += nums[j];
            while(sum > target)
                sum -= nums[i++];
            
            if(sum == target)
                maxLen = max(maxLen, j-i+1);
        }

        return maxLen == INT_MIN ? -1 : n-maxLen;
    }
    
};