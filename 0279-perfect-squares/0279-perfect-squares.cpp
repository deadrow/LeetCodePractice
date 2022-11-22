class Solution {
public:
    vector<int> squares;
    vector<vector<int>>memo;
    int dp(int i, int target)
    {
        if(target == 0)
            return 0;
        
        if(i < 0 || target < 0)
            return INT_MAX;
        
        if(memo[i][target] != -1)
            return memo[i][target];
        
        int take = INT_MAX;
        if(squares[i] <= target)
        {
            int ret = dp(i, target-squares[i]);
            take = ret != INT_MAX ? ret+1: take;
        }
        
        int leave = dp(i-1, target);
        
        return memo[i][target] = min(take, leave);
    }
    
    int numSquares(int n) {
        int i = sqrt(n);
        while(i >= 1)
        {
            squares.push_back(i*i);
            i--;
        }
        
        memo.resize(squares.size(), vector<int>(n+1,-1));
        return dp(squares.size()-1, n);
    }
};