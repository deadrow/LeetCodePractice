class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<int>& coins, int i, int amount)
    {
        if(amount == 0)
            return 0;
        
        if(i < 0 || amount < 0)
            return INT_MAX;
        
        if(memo[i][amount] != -1)
            return memo[i][amount];
        
        int take = INT_MAX;
        if(coins[i] <= amount)
        {
            int res = dp(coins, i, amount - coins[i]);
            take = res != INT_MAX ? res+1 : take;
        }

        int leave = dp(coins, i-1, amount);
        return memo[i][amount] = min(take,leave);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1) return 0;
        
        memo.resize(coins.size()+1, vector<int>(amount+1,-1));
        
        // Unbounded knapsack solution
        int ret = dp(coins, coins.size()-1, amount);
        return ret != INT_MAX ? ret : -1;
        
        /*
        vector<int> dp(amount+1, amount+1);
        
        dp[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            for(auto coin : coins)
            {
                if(i-coin < 0) continue;
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        
        return (dp[amount] == amount+1) ? -1: dp[amount];
        */
    }
};