class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };
    vector<vector<int>>memo;
    int dfs(int n, int cur_i)
    {
        if(n == 1)
            return 1;

        if(memo[n][cur_i] != -1)
            return memo[n][cur_i];

        int sum = 0;
        for(auto it : jumps[cur_i])
        {
            sum = (sum + dfs(n-1, it)) % MOD;
        }

        memo[n][cur_i] = sum;
        return sum;
    }

    int knightDialer(int n) {
        if(n == 1) return 10;

        int count = 0;
        vector<int>nums{0,1,2,3,4,6,7,8,9};
        memo.resize(n+1, vector<int>(11,-1));

        for(auto it : nums)
        {
            count = (count + dfs(n, it)) % MOD;
        }
            
        return count;
    }
};