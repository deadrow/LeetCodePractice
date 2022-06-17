class Solution {
public:
    bool isPow(int n)
    {
        if(n == 1)
            return true;
        
        return (n % 3 == 0) && isPow(n/3);
    }
    
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        
        if(n == 1)
            return true;
        
        return isPow(n);
    }
};