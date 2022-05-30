class Solution {
public:
    vector<vector<int>>memo;
    int editDistance(string& word1, string& word2, int m, int n)
    {
        if(m == 0)
            return n;
        
        if(n == 0)
            return m;
        
        if(memo[m][n] != -1)
            return memo[m][n];
        
        if(word1[m-1] == word2[n-1])
            return editDistance(word1, word2, m-1, n-1);
        
        return memo[m][n] = 1 + min({editDistance(word1, word2, m, n-1),
                                    editDistance(word1, word2, m-1, n),
                                    editDistance(word1, word2, m-1, n-1)});
    }
    
    int minDistance(string word1, string word2) {
        memo.resize(word1.size()+1, vector<int>(word2.size()+1, -1));
        return editDistance(word1, word2, word1.size(), word2.size());
    }
};