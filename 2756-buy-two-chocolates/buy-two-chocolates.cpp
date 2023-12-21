class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        int ret = money - (prices[0]+prices[1]);

        return ret < 0 ? money: ret;
    }
};