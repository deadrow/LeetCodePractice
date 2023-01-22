class Solution {
public:
    vector<vector<string>> res;
    
    bool isPalindrome(string& s)
    {
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    void backtrack(string& s, vector<string>& cur, int i, int j)
    {
        if(i>=j)
        {
            res.push_back(cur);
            return;
        }

        for(int k=i;k<j;k++)
        {
            string sub = s.substr(i, k-i+1);
            if(isPalindrome(sub))
            {
                cur.push_back(sub);
                backtrack(s, cur, k+1, j);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>cur;
        backtrack(s, cur, 0, s.size());
        return res;
    }
};