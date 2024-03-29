class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<int>& prices, int fee, int cur_i, int buy)
    {
        if(cur_i >= prices.size())
            return 0;

        if(memo[cur_i][buy] != -1)
            return memo[cur_i][buy];

        int leave = dp(prices, fee, cur_i+1, buy);
        int ans = 0;
        if(buy)
            ans = -prices[cur_i] + dp(prices, fee, cur_i+1, 0);
        else
            ans = prices[cur_i] - fee + dp(prices, fee, cur_i+1, 1);

        return memo[cur_i][buy] = max(ans, leave);
    }

    int maxProfit(vector<int>& prices, int fee) {
        memo.resize(prices.size(), vector<int>(2, -1));
        return dp(prices, fee, 0, 1);
    }
};