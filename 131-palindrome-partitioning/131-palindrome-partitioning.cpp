class Solution {
public:
    vector<vector<string>> ret;
    bool isPalindrome(string &s) {
        int i=0;
        int j=s.size()-1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    
    // matrix chain multiplication solution
    void solve(string& s, int i, int j, vector<string> cur)
    {
        if(i >= j) // i == j because single string is itself palindrome
        {
            ret.push_back(cur);
            return;
        }
        
        for(int k=i;k<=j-1;k++)
        {
            // if(k-i+1 == 1 || isPalindrome(s, i, k))
            string temp = s.substr(i, k-i+1);
            if(isPalindrome(temp))
            {
                cur.push_back(temp);
                solve(s, k+1, j, cur);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        solve(s, 0, s.size(), cur);
        return ret;
    }
};