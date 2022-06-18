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
    
    void solve(string& s, int i, vector<string>& cur)
    {
        if(i >= s.length())
        {
            ret.push_back(cur);
            return;
        }
        
        for(int k=i;k<s.length();k++)
        {
            string temp = s.substr(i, k-i+1);
            if(isPalindrome(temp))
            {
                cur.push_back(temp);
                solve(s, k+1, cur);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        solve(s, 0, cur);
        return ret;
    }
};