class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int cur = nums[0];
        for(int i=1;i<nums.size();i++)
            cur ^= nums[i];
        
        return cur;
    }
};