class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<int>& coins, int i, int amount)
    {
        if(amount == 0)
            return 1;
        
        if(i < 0)
            return 0;
        
        if(memo[i][amount] != -1)
            return memo[i][amount];
        
        int take = 0;
        if(coins[i] <= amount)
        {
            take = dp(coins, i, amount - coins[i]);
        }
        
        int leave = dp(coins, i-1, amount);
        return memo[i][amount] = take+leave;
    }
    
    int change(int amount, vector<int>& coins)
    {
        memo.resize(coins.size()+1, vector<int>(amount+1,-1));

        // Unbounded knapsack solution
        return dp(coins, coins.size()-1, amount);
        
        /*
        vector<int>dp(amount+1);
        dp[0] = 1;
        
        for(auto coin : coins)
        {
            for(int i=0;i<=amount;i++)
            {
                if(i-coin >= 0)
                    dp[i] += dp[i-coin];
            }
        }
        
        return dp[amount];
        */
    }
};