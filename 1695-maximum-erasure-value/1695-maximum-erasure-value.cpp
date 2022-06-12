class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> cache;
        
        int i=0;
        int j=0;
        int sum = 0;
        int maxSum = INT_MIN;
        while(j < nums.size())
        {
            cache[nums[j]]++;
            sum += nums[j];
            
            if(cache.size() == j-i+1)
            {
                maxSum = max(sum, maxSum);
                j++;
            }
            else if(cache.size() < j-i+1)
            {
                while(cache.size() < j-i+1)
                {
                    cache[nums[i]]--;
                    sum -= nums[i];
                    if(cache[nums[i]] == 0)
                        cache.erase(nums[i]);
                    
                    i++;
                }
                j++;
            }
        }
        
        return maxSum;
    }
};