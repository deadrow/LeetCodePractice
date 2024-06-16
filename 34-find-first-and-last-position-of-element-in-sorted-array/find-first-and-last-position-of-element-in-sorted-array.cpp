class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};

        int low = 0;
        int high = nums.size();
        // Find start point
        while(low<high){
            int mid =low+(high-low)/2;
            if(nums[mid] >= target)
                high = mid;
            else
                low = mid+1;
        }

        if(low >= nums.size() or nums[low] != target) return {-1,-1};
        int start = low;

        low = 0;
        high = nums.size();
        while(low<high){
            int mid =low+(high-low)/2;
            if(nums[mid] <= target)
                low = mid+1;
            else
                high = mid;
        }

        return {start, low-1};
    }
};