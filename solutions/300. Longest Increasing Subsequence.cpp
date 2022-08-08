class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>subSet;
        subSet.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > subSet.back())
                subSet.push_back(nums[i]);
            else
            {
                auto it = lower_bound(subSet.begin(), subSet.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return subSet.size();
    }
};
