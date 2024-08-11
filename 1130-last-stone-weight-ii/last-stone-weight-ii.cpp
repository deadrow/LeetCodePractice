class Solution {
public:
    int totalSum=0;
    vector<vector<int>>memo;
    int dp(vector<int>& stones, int curSum, int i){
        if(i>= stones.size()) return abs(totalSum-2*curSum);
        if(memo[curSum][i] != -1) return memo[curSum][i];
        int take = dp(stones, curSum+stones[i], i+1);
        int leave = dp(stones, curSum, i+1);
        return memo[curSum][i] = min(take, leave);
    }
    int lastStoneWeightII(vector<int>& stones) {
        totalSum = accumulate(stones.begin(), stones.end(),0);
        memo.resize(totalSum, vector<int>(stones.size()+1, -1));
        return dp(stones, 0, 0);
    }
};