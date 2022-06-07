class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> cache;
        
        int i=0;
        int j=0;
        
        int maxLen = 0;
        int maxKeyCount = 0;
        while(j < nums.size())
        {
            if(nums[j] == 1)
            {
                cache[nums[j]]++;
                maxKeyCount = max(maxKeyCount, cache[nums[j]]);
            }

            int windowSize = j-i+1;
            
            if(windowSize - maxKeyCount <= k)
            {
                j++;
                maxLen = max(maxLen, windowSize);
            }
            else
            {
                cache[nums[i]]--;
                i++;
                j++;
            }
        }
        
        return maxLen;
    }
};