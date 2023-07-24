class Solution {
public:
    double fastPow(double x, long n)
    {
        if(n == 0)
            return 1.0;
        
        double ret = fastPow(x, n/2);
        double res = ret*ret;
        if(n % 2 == 1 || n % 2 == -1)
            res *= x;
        return res;
    }

    double myPow(double x, int n) {
        if(n < 0)
            x = 1/x;
        return fastPow(x, n);
    }
};