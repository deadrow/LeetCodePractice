class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<vector<int>>>memo;
    int dfs(int n, int numAbsents, int numLates) {
        if(numAbsents >= 2 or numLates >= 3) return 0;
        if(n == 0) return 1;

        if(memo[n][numAbsents][numLates] != -1)
            return memo[n][numAbsents][numLates];

        int count = 0;
        // Since we have already checked numAbsents and
        // numLates in the beginning, Selecting P or A will
        // reset numLates because if numLates ==2 and if
        // we select P or A, PP doesn't make ineligible.

        // select P.
        count = dfs(n-1, numAbsents, 0) % MOD;
        //select A
        count = (count + dfs(n-1, numAbsents+1, 0)) % MOD;
        //select L
        count = (count + dfs(n-1, numAbsents, numLates+1)) % MOD;
        return memo[n][numAbsents][numLates]= count;
    }
    int checkRecord(int n) {
        memo.resize(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return dfs(n, 0,0);
    }
};