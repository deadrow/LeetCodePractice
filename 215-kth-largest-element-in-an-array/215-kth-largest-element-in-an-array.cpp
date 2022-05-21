class Solution {
public:
    int quickselect(vector<int>& nums, int low, int high, int k)
    {
        int pivot = nums[high];
        int left = low;
        
        for(int i=low;i<high;i++)
        {
            if(nums[i] <= pivot)
            {
                swap(nums[left], nums[i]);
                left++;
            }
        }
        
        swap(nums[left], nums[high]);
        
        if(k < left) // meaning in 1st half
            return quickselect(nums, low, left-1, k);
        else if(k > left)
            return quickselect(nums, left+1, high, k);
        return nums[left];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int low = 0;
        int high = nums.size()-1;
        return quickselect(nums, low, high, nums.size()-k);
    }
};