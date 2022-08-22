class Solution {
public:
    bool isPowerOfFour1(int n) {
        if(n>1) while(n%4 == 0) n /= 4;
        
        return n == 1;
    }
    
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n-1)) == 0) && ((n & 0xaaaaaaaa) == 0);
    }
};