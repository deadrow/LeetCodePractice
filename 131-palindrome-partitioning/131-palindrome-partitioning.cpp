class Solution {
public:
    vector<vector<string>> ret;
    vector<vector<bool>> memo;
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
    
    void solve(string& s, int start, vector<string>& cur)
    {
        if(start >= s.length())
        {
            ret.push_back(cur);
            return;
        }
        
        for(int end=start;end<s.length();end++)
        {
            string temp = s.substr(start, end-start+1);
            if(s[start] == s[end] && (end-start <= 2 || memo[start+1][end-1]))
            {
                memo[start][end] = true;
                cur.push_back(temp);
                solve(s, end+1, cur);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        memo.resize(s.length(), vector<bool>(s.length()));
        vector<string> cur;
        solve(s, 0, cur);
        return ret;
    }
};