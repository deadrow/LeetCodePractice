class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int high=nums.size();
        while(low<high){
            int mid = low + (high-low)/2;
            if(mid-1 >=0 and nums[mid]> nums[mid-1])
                low = mid+1;
            else
                high = mid;
        }
        return low >0 ? low-1 : 0;
    }
};