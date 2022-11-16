class Solution {
public:
    int mySqrt(int x) {

        long low = 0;
        long high = (long)x+1;
        while(low < high)
        {
            int mid = low + (high-low)/2;
            
            if((long long)mid*mid > x)
                high = mid;
            else
                low = mid+1;
        }
        
        return low-1;
    }
};