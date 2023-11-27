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
        if(n == 0)
            return 1;

        if(memo[n][cur_i] != -1)
            return memo[n][cur_i];

        int sum = 0;
        for(const auto& it : jumps[cur_i])
        {
            sum = (sum + dfs(n-1, it)) % MOD;
        }

        memo[n][cur_i] = sum;
        return sum;
    }

    int knightDialer(int n) {
        int count = 0;
        vector<int>nums{0,1,2,3,4,6,7,8,9};
        memo.resize(n+1, vector<int>(10,-1));

        for(int i=0;i<10;i++)
        {
            count = (count + dfs(n-1, i)) % MOD;
        }
            
        return count;
    }
};