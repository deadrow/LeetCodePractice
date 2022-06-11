class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int>prefix(n+1);

        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total-x;
        if(target < 0)
            return -1;
        
        int i=0;
        int j=0;
        int sum = 0;
        int maxLen = INT_MIN;
        while(j < n)
        {
            sum += nums[j];
              
            if(sum < target)
                j++;
            else if(sum == target)
            {
                maxLen = max(maxLen, j-i+1);
                j++;
            }
            else if(sum > target)
            {
                while(sum > target)
                    sum -= nums[i++];
                if(sum == target)
                    maxLen = max(maxLen, j-i+1);
                j++;
            }
        }
        
        return maxLen == INT_MIN ? -1 : n-maxLen;
    }
    
};