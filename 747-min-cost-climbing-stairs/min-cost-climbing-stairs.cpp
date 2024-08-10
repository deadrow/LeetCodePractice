class Solution {
public:
    int INF = 1e5;
    vector<int>memo;
    int dp(vector<int>& cost, int i){
        if(i >= cost.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int take_1 = cost[i] + dp(cost, i+1);
        int take_2 = cost[i] + dp(cost, i+2);
        return memo[i]=min({take_1, take_2});
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size(), -1);
        return min(dp(cost, 0) , dp(cost, 1));
    }
};