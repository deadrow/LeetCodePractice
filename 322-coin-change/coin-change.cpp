class Solution {
public:
    vector<int>memo;
    int dp(vector<int>& coins, int target){
        if(target == 0) return 0;
        if(memo[target] != -1) return memo[target];
        int count = INT_MAX;
        for(auto& it : coins){
            if(target-it >=0) {
                int ret = dp(coins, target-it);
                if(ret != INT_MAX)
                    count = min(count, 1+ret);
            }
        }
        return memo[target]=count;
    }
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount+1, -1);
        int ret = dp(coins, amount);
        return ret == INT_MAX ? -1 : ret;
    }
};