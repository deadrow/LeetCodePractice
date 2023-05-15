class Solution {
public:
    vector<int>memo;
    int targetSum = 0;
    bool dfs(vector<int>& matchsticks, int mask, int target, int k)
    {
        if(k == 1)
            return true;
        
        if(memo[mask] != -1)
            return memo[mask];

        if(target == 0)
            return dfs(matchsticks, mask, targetSum, k-1);

        for(int i=0;i<matchsticks.size();i++)
        {
            if((mask >> i) & 1 || target - matchsticks[i] < 0)
                continue;

            mask = mask | (1 << i);
            if(dfs(matchsticks, mask, target - matchsticks[i], k))
                return memo[mask] = true;
             mask = mask ^ (1 << i);
        }

        return memo[mask] = false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if(totalSum % 4 != 0)
            return false;

        targetSum = totalSum/4;

        int mask = 0;
        memo.resize(1 << matchsticks.size(), -1);
        return dfs(matchsticks, mask, targetSum, 4);
    }
};