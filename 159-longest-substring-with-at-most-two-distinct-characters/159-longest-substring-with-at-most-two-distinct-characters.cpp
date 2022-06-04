class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> cache;
        
        int i=0;
        int j=0;
        int k = 2;
        int maxLen = 0;
        while(j < s.size())
        {
            cache[s[j]]++;
            
            if(cache.size() <= k)
            {
                maxLen = max(maxLen, j-i+1);
                j++;
            }
            else if(cache.size() > k)
            {
                while(cache.size() > k)
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