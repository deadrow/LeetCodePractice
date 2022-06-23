class Solution {
public:
    vector<vector<int>> memo;
    bool dp(string& s, string& p, int i, int j)
    {
        int sn = s.size();
        int pn = p.size();
        
        if(j == pn)
            return i == sn;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        bool firstMatch = (i < sn && (s[i] == p[j] || p[j] == '.'));
        
        if(j+1<pn && p[j+1] == '*')
        {
            // don't use * and just increment
            if(dp(s, p, i, j+2))
                return memo[i][j] = true;
            
            if(firstMatch && dp(s, p, i+1, j))
                return memo[i][j] = true;
        }
        
        if(firstMatch)
            return memo[i][j] = dp(s, p, i+1, j+1);
        
        return memo[i][j] = false;
    }
    bool isMatch(string s, string p) {
        memo.resize(s.size()+1, vector<int>(p.size()+1,-1));
        return dp(s, p, 0, 0);
    }
};