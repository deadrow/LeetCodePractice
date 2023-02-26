class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // binary search template from 
        // https://leetcode.com/discuss/general-discussion/786126/Python-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems
        
        long ab = (long)a*b/gcd(a,b); 
        long bc = (long)b*c/gcd(b,c); 
        long ac = (long)a*c/gcd(a,c); 
        long abc = (long)a*bc/gcd(a,bc); 
        
        auto enough = [=](int num){
            long numbers = (long)num/a + (long)num/b + (long)num/c - num/ab - num/bc - num/ac + (long)num/abc;
            return numbers >= n;
        };
      
        int left = 1;
        int right = 2*(int)1e9;
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(enough(mid))
                right = mid;
            else
                left = mid+1;
        }
        
        return left;
    }
};