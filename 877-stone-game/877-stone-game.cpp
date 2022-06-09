class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& piles, int low, int high, int n)
    {
        if(low >=n || high < 0)
            return 0;
        
        if(memo[low][high] != -1)
            return memo[low][high];
        
        int fromStart = piles[low] + dp(piles, low+2, high, n);
        int fromEnd = piles[high] + dp(piles, low, high-2, n);
        int ans = max(fromStart , fromEnd);
        return memo[low][high] = ans;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memo.resize(n, vector<int>(n,-1));
        
        int total = accumulate(piles.begin(), piles.end(), 0);
        int ans = dp(piles, 0, n-1, n);
        return ans > total-ans;
    }
};