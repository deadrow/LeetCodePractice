class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while(i < nums.size())
        {
            long correct = (long)nums[i] - 1;
            if(correct >= 0 && correct < nums.size() && nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[correct])
                swap(nums[i], nums[correct]);
            else
                i++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(i+1 != nums[i])
                return i+1;
        }
        
        return nums.size()+1;
    }
};