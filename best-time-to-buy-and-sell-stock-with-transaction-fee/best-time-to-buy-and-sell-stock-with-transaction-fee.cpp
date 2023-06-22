class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<int>& prices, int fee, int cur_i, int buy)
    {
        if(cur_i >= prices.size())
            return 0;

        if(memo[cur_i][buy] != -1)
            return memo[cur_i][buy];
        if(buy)
        {
            int bought = -prices[cur_i] + dp(prices, fee, cur_i+1, 0);
            int leave = dp(prices, fee, cur_i+1, 1);
            return memo[cur_i][buy] = max(bought, leave);
        }
        else
        {
            int sell = prices[cur_i] - fee + dp(prices, fee, cur_i+1, 1);
            int leave = dp(prices, fee, cur_i+1, 0);
            return memo[cur_i][buy] = max(sell, leave);
        }

        return 0;
    }

    int maxProfit(vector<int>& prices, int fee) {
        memo.resize(prices.size(), vector<int>(2, -1));
        return dp(prices, fee, 0, 1);
    }
};