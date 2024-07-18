class Solution {
public:
    double myPowUtil(double x, int n){
        if(n == 0) return 1;
        double ret = myPowUtil(x, n/2);
        return n & 1 ? ret*ret*x : ret*ret;
    }
    double myPow1(double x, int n) {
        if(n<0) x = 1/x;
        return myPowUtil(x, n);
    }
    //iterative
    double myPow(double x, int n) {
        if(n<0) x = 1/x;
        double ret=1;
        while(n){
            if(n& 1)
                ret *=x;
            x *=x;
            n /=2;
        }
        return ret;
    }
};