class Solution {
public:
    vector<vector<int>> memo;
    
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    
    // matrix chain multiplication solution
    int solve(string& s, int i, int j)
    {
        if((i >= j) || isPalindrome(s, i, j)) // i == j because single string is itself palindrome
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int min_cut = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            if(isPalindrome(s, i, k))
            {
                min_cut = min(min_cut, 1+solve(s, k+1, j));
            }
        }
        
        return memo[i][j] = min_cut;
    }
    
    int minCut(string s) {
        int size = s.size();
        memo.resize(size+1, vector<int>(size+1, -1));
        return solve(s, 0, s.size()-1);
    }
};