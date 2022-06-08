class Solution {
public:
    vector<vector<vector<int>>> memo;
    int dp(vector<int>& prices, int i, int k, int buy)
    {
        if(i >= prices.size() || k < 0)
            return 0;
        
        if(memo[i][k][buy] != -1)
            return memo[i][k][buy];
        
        int max_profit = 0;
        if(buy)
        {
            int bought = -prices[i] + dp(prices, i+1, k-1, 0);
            int skip = dp(prices, i+1, k, buy);
            max_profit = max(bought, skip);
        }
        else
        {
            int sold = prices[i] + dp(prices, i+1, k, 1);
            int skip = dp(prices, i+1, k, buy);
            max_profit = max(sold, skip);
        }

        return memo[i][k][buy] = max_profit;
    }
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(), vector<vector<int>>(3, vector<int>(2, -1)));
        return dp(prices, 0, 2, 1);
    }
};