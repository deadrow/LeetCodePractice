class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int curMax = INT_MIN;
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] < curMax)
            {
                ans += curMax - nums[i];
                nums[i] = curMax;
            }
            
            curMax = max(0, nums[i]+1);
        }
        
        return ans;
    }
};