class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& stones, int i, int curSum, int totalSum)
    {
        if(i < 0)
            return abs(totalSum - 2* curSum);
        
        if(memo[i][curSum] != -1)
            return memo[i][curSum];
        
        // 0/1 knapsack
        // Find min of taking stone and leaving stone
        int take = dp(stones, i-1, curSum + stones[i], totalSum);
        int leave = dp(stones, i-1, curSum, totalSum);
        
        return memo[i][curSum] = min(take, leave);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        
        memo.resize(stones.size()+1, vector<int>(totalSum+1, -1));
        
        return dp(stones, stones.size()-1, 0, totalSum);
    }
};