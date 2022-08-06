class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        vector<int> pattern(n);
        
        int j=0;
        for(int i=1;i<n;i++)
        {
            while(j>0 && needle[i] != needle[j]) j = pattern[j-1];
            if(needle[i] == needle[j]) j++;
            pattern[i] = j;
        }
        
        j = 0;
        for(int i=0;i<m;i++)
        {
            while(j>0 && haystack[i] != needle[j]) j = pattern[j-1];
            if(needle[j] == haystack[i])
                j++;
            if(j == n)
                return i-n+1;
        }
        
        return -1;
    }
};