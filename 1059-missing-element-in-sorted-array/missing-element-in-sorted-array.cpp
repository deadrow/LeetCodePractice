class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        // LOGIC
        // If arr = [4,7,9,10] and k = 3
        // If we say that there is no element
        // missing the array should be
        // [4,5,6,7] If we negate both array
        // we find how many elements at each index is missing
        // So the results would be [0, 2, 3, 3]. Now we 
        // can binary search for k and we find out at which low
        // and high index between which k lies
        int low = 0;
        int high = nums.size();
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid]-(nums[0]+mid) < k)
                low = mid+1;
            else
                high = mid;
        }

        cout << low << "," << high;
        // What to return
        // Here is the logic. For above example low and high both stops 
        // at index 1. This is upper bound. So we take low-1
        // At index 1 there are 2 elements missing. So the formula would be
        // arr[low-1] + k - (arr[low-1] - (arr[0] + low - 1)) which would get
        // simplified as k + arr[0] + low - 1;

        return low+k+nums[0]-1; // here is logic for this
    }
};