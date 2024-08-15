class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>>memo;
    int dp(int n, int k, int target){
        if(target<0 or n<0) return 0;
        if(target == 0 and n==0) return 1;
        if(memo[n][target] != -1) return memo[n][target];
        int count=0;
        for(int i=1;i<=k;i++)
            count = (count + dp(n-1, k, target-i)) % MOD;
        return memo[n][target]=count;
    }
    int numRollsToTarget(int n, int k, int target) {
        memo.resize(n+1, vector<int>(target+1, -1));
        return dp(n, k, target);
    }
};