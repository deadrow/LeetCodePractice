class Solution {
public:
    int findKthPositive1(vector<int>& arr, int k) {
        vector<bool>nums(2000);
        for(auto it : arr){
            nums[it] = true;
        }
        int i=1;
        for(;i<nums.size();i++) {
            if(!nums[i]) k--;
            if(k == 0) break;
        }

        return i;
    }
    int findKthPositive(vector<int>& arr, int k) {
        // LOGIC
        // If arr = [2, 3, 4, 7, 11] and k = 5
        // If we say that there is no element
        // missing the array should be
        // [1,2,3,4,5] If we negate both array
        // we find how many elements at each index is missing
        // So the results would be [1, 1, 1, 3, 6]. Now we 
        // can binary search for k and we find out at which low
        // and high index between which k lies
        int low = 0;
        int high = arr.size();
        while(low < high){
            int mid = low + (high-low)/2;
            if(arr[mid]-(mid+1) < k)
                low = mid+1;
            else
                high = mid;
        }

        cout << low << "," << high;
        // What to return
        // Here is the logic. For above example low and high both stops 
        // at index 4. This is upper bound. So we take low-1
        // At index 3 there are  elements missing. So we add k-3 that is
        // 2 to arr[low-1] =  7 + 2 so 9 becomes our 5th missing element
        // So arr[low-1] + (k - (arr[low-1] - low)) which becomes low+k

        return low+k; // here is logic for this

    }
};