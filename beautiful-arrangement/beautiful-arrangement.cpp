class Solution {
public:
    vector<int>memo;
    int dfs(int mask, int cur_i, int n)
    {
        if(cur_i > n)
            return 1;

        if(memo[mask] != -1)
            return memo[mask];
        int count = 0;
        for(int i=1;i<=n;i++)
        {
            if((mask >> i) & 1)
                continue;
            
            if(cur_i % i == 0 or i % cur_i == 0)
            {
                mask = mask | (1 << i);
                count += dfs(mask, cur_i+1, n);
                mask = mask ^ (1 << i);
            }
        }
        return memo[mask] = count;
    }

    int countArrangement(int n) {
        int mask = 0;
        memo.resize(1<<(n+1), -1);
        return dfs(mask, 1, n);
    }
};