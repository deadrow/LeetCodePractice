class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& prices, int i, int buy, int fee)
    {
        if(i >= prices.size())
            return 0;
        
        if(memo[i][buy] != -1)
            return memo[i][buy];
        
        int max_profit = 0;
        if(buy)
        {
            int bought = -prices[i] + dp(prices, i+1, 0, fee) - fee;
            int skip = dp(prices, i+1, buy, fee);
            max_profit = max(bought, skip);
        }
        else
        {
            int sold = prices[i] + dp(prices, i+1, 1, fee);
            int skip = dp(prices, i+1, buy, fee);
            max_profit = max(sold, skip);
        }

        return memo[i][buy] = max_profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memo.resize(prices.size(), vector<int>(2, -1));
        return dp(prices, 0, 1, fee);
    }
};