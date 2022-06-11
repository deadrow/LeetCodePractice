class Solution {
public:
    vector<vector<vector<int>>> memo;
    bool dp(string& s1, string& s2, string& s3, int i, int j, int k)
    {
        if(i >= s1.size() && j >= s2.size() && k >= s3.size())
            return true;
        
        if(k >= s3.size())
            return false;
        
        if(memo[i][j][k] != -1)
            return memo[i][j][k];
        
        bool takeFirst = false;
        if(s1[i] == s3[k])
            takeFirst = dp(s1, s2, s3, i+1, j, k+1);
        
        bool takeSecond = false;
        if(s2[j] == s3[k])
            takeSecond = dp(s1, s2, s3, i, j+1, k+1);
        
        return memo[i][j][k] = takeFirst || takeSecond;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memo.resize(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1,-1)));
        return dp(s1, s2, s3, 0, 0, 0);
    }
};