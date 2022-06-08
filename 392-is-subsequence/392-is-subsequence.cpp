class Solution {
public:
    vector<vector<int>>memo;
    
    int lcs(string& s, string& t, int i, int j)
    {
        if(i < 0 || j < 0)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        if(s[i] == t[j])
            return memo[i][j] = 1+lcs(s, t, i-1, j-1);

        return memo[i][j] = max(lcs(s, t, i-1, j), lcs(s, t, i, j-1));
    }
    bool isSubsequence(string s, string t) {
        
        memo.resize(s.size(), vector<int>(t.size(),-1));
        int len = lcs(s, t, s.size()-1, t.size()-1);
        return len == s.size();
    }
};