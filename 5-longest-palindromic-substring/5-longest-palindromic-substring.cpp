class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        // expand around center solution
        string res;
        int maxLength = 0;
        
        for(int i=0;i<n;i++)
        {
            // odd case 'aba'
            int left = i;
            int right = i;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(right-left+1 > maxLength)
                {
                    maxLength = right-left+1;
                    res = s.substr(left, maxLength);
                }
                left--;
                right++;
            }
            
            // even case like 'aa'
            left = i;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if(right-left+1 > maxLength)
                {
                    maxLength = right-left+1;
                    res = s.substr(left, maxLength);
                }
                left--;
                right++;
            }
        }
        
        return res;
    }
};