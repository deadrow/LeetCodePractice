class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> cache;
        
        int i=0;
        int j=0;
        int maxLen = 0;
        while(j < s.size())
        {
            cache[s[j]]++;
            
            if(cache.size() == j-i+1)
            {
                maxLen = max(maxLen, j-i+1);
                j++;
            }
            else if(cache.size() < j-i+1)
            {
                while(cache.size() < j-i+1)
                {
                    cache[s[i]]--;
                    if(cache[s[i]] == 0)
                        cache.erase(s[i]);
                    
                    i++;
                }
                j++;
            }
        }
        
        return maxLen;
    }
};