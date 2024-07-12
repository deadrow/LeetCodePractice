class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int high=arr.size();
        while(low<high){
            int mid = low + (high-low)/2;
            if(mid-1 >=0 and arr[mid]> arr[mid-1])
                low = mid+1;
            else
                high = mid;
        }
        return low >0 ? low-1 : 0;
    }
};