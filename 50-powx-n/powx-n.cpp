class Solution {
public:
    double myPowUtil(double x, int n) {
        if(n==0) return 1.0;

        double half = myPowUtil(x, n/2);
        return n%2 ? x*half*half : half*half;
    }
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1/x;
        }
            
        return myPowUtil(x, n);
    }
};