class Solution {
public:
    double myPowUtil(double x, int n){
        if(n == 0) return 1;
        double ret = myPowUtil(x, n/2);
        return n & 1 ? ret*ret*x : ret*ret;
    }
    double myPow(double x, int n) {
        if(n<0) x = 1/x;
        return myPowUtil(x, n);
    }
};