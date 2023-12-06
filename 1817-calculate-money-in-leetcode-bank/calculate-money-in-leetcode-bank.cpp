class Solution {
public:
    /* arithmetic sum
    https://www.cuemath.com/algebra/arithmetic-sequence/
     e.g 1 5 9 13
     first = 1
     last = first + (n-1)*diff
     sum = (first + last)*n/2 or
     sum = (2*first + (n-1)*diff)/2
    */
    
    int totalMoney(int n) {
        int k = n/7;
        int f = 28;
        int l = f + (k-1)*7;
        int sum = k*(f+l)/2;

        int last_k = n%7;
        int lastSum = last_k*(2*(k+1) + (last_k-1))/2;
        return sum + lastSum;
    }
};