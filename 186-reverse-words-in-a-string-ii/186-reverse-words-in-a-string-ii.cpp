class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        
        int lastSpace = -1;
        for(int i=0;i<s.size();i++)
        {
            if(isspace(s[i]))
            {
                if(lastSpace == -1)
                    reverse(s.begin(), s.begin()+i);
                else
                    reverse(s.begin() + lastSpace+1, s.begin()+i);
                
                lastSpace = i;
            }
        }
        
        reverse(s.begin() + lastSpace+1, s.end());
    }
};