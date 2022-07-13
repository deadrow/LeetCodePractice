class Solution {
public:
    int dfs(int& mask, int cur_i, int n)
    {
        if(cur_i > n)
            return 1;
        
        int count = 0;
        for(int i=1;i<=n;i++)
        {
             if(((mask >> i) & 1) != 1 && (cur_i % i == 0 || i % cur_i == 0))
             {
                 mask = mask | (1 << i);
                 count += dfs(mask, cur_i+1, n);
                 mask = mask ^ (1 << i);
             }
        }
        
        return count;
    }
    
    int countArrangement(int n) {
        int mask = 0;
        return dfs(mask, 1, n);
    }
};