class Solution {
public:
    // This is coin change problem
    // Basically n is given and there are 2 ways(or coins)
    // given. Find how many ways. For e.g if n = 5;
    // coins are 1, 2. So how many ways to make 5
    vector<int>memo;
    int MOD = 1000000007;
    int dp(int len, int zero, int one)
    {
        if(len == 0)
            return 1;

        if(len < 0)
            return 0;

        if(memo[len] != -1)
            return memo[len];
        
        int takeZero = dp(len-zero, zero, one);
        int takeOne = dp(len-one, zero, one);
        return memo[len] = (takeZero+takeOne) % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memo.resize(high+1,-1);
        int total = 0;
        for(int i=low;i<=high;i++)
        {
            total += dp(i, zero, one);
            total %= MOD;
        }

        return total;
    }
};