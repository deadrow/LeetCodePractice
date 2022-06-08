class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_i = s.size()-1;
        int t_i = t.size()-1;
        
        int count = 0;
        while(s_i >= 0 && t_i >= 0)
        {
            if(s[s_i] == t[t_i])
            {
                count++;
                s_i--;
                t_i--;
            }
            else
                t_i--;
        }
        
        return count == s.size();
    }
};