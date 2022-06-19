class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
        while(n)
        {
            n /= 5;
            zeros += n;
        }
        
        return zeros;
    }
};