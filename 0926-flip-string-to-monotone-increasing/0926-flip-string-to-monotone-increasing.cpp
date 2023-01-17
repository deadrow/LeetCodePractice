class Solution {
public:
    vector<vector<int>>memo;
    int dp(string& s, int cur, bool cont)
    {
        if(cur == s.size())
            return 0;
        
        if(memo[cur][cont] != -1)
            return memo[cur][cont];
        
        if(cont)
        {
            if(s[cur] == '1')
                return memo[cur][cont] = dp(s, cur+1, cont);
            else
                return memo[cur][cont]= 1+dp(s, cur+1, cont);
        }
        else
        {
            // not continuos ones.
            // If s[cur] == '0', flip to 1 and start continous 
            // else s[cur] == '1' we have to flip it to make 0s continues
            if(s[cur] == '0')
                return memo[cur][cont] = min(1+dp(s, cur+1, true), dp(s, cur+1, false));
            return memo[cur][cont]= min(1+dp(s, cur+1, false), dp(s, cur+1, true));
        }
    }
    
    int minFlipsMonoIncr(string s) {
        // check how many 0s and 1s when 1 is started
        
        memo.resize(s.size(), vector<int>(2, -1));
        return dp(s, 0, false);
    }
};