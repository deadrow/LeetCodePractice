class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        int curSum = 0;
        int minLen = INT_MAX;
        while(j<n)
        {
            curSum += nums[j];

            if(curSum < target)
                j++;
            else if(curSum == target)
            {
                minLen = min(j-i+1, minLen);
                j++;
            }
            else
            {
                while(curSum >= target)
                {
                    minLen = min(j-i+1, minLen);
                    curSum -= nums[i];
                    i++;
                }

                j++;
            }
        }

        // cout << i;
        // if(i != n-1)
        //     minLen = min(n-i, minLen);

        return minLen == INT_MAX ? 0 : minLen;
    }
};