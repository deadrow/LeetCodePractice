class Solution {
public:
    bool dp(int n)
    {
        if(n == 1)
            return false;
        
        if(n == 2)
            return true;
        
        for(int i=1;i<=n;i++)
        {
            if(n % i == 0)
                return !dp(n-i);
        }
        
        return false;
            
    }
    bool divisorGame(int n) {
        return dp(n);
    }
};