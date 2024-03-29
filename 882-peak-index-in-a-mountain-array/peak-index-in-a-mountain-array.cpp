class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size();

        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(arr[mid+1] > arr[mid])
                left = mid+1;
            else
                right = mid;
        }

        return left;
    }
};