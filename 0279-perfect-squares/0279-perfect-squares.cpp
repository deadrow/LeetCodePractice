class Solution {
public:
    vector<int>squares;
    vector<int>memo;
    int dp(int target)
    {
        if(target == 0)
            return 0;
        
        if(memo[target] != -1)
            return memo[target];
        
        int ret = INT_MAX;
        for(auto it : squares)
        {
            if(target >= it)
            {
                ret = min(ret, dp(target-it)+1);
            }
        }
        
        return memo[target] = ret;
    }
    
    int numSquares(int n) {
        
        int i = 1;
        while(i*i <= n)
        {
            squares.push_back(i*i);
            i++;
        }
        
        memo.resize(n+1, -1);
        return dp(n);
    }
};