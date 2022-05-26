class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<optional<bool>>> memoPalindrome;
    
    bool isPalindrome(string &s, int start, int end) {
        if (start >= end) return true;
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != nullopt)
            return (memoPalindrome[start][end] == true);
        memoPalindrome[start][end] =
            (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
        return (memoPalindrome[start][end] == true);
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

        memoPalindrome.resize(size, vector<optional<bool>>(size, nullopt));
        memo.resize(size+1, vector<int>(size+1, -1));
        return solve(s, 0, s.size()-1);
    }
};