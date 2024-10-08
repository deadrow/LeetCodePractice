class Solution {
public:
    vector<int>memo;
    int dp(int n){
        if(n==0 or n==1) return 1;
        if(memo[n] != -1) return memo[n];
        return memo[n]=dp(n-1)+dp(n-2);
    }
    int climbStairs(int n) {
        memo.resize(n+1, -1);
        return dp(n);
    }
};