class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=1;i<n;i++)
        {
            if(n % i == 0)
            {
                string pat;
                for(int j=0;j<n/i;j++)
                {
                    pat += s.substr(0,i);
                }
                if(pat == s)
                    return true;
            }
        }

        return false;
    }
};