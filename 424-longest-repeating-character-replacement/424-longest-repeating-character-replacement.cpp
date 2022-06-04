class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> cache;
        
        int i=0;
        int j=0;
        int maxLen = 0;
        while(j < s.size())
        {
            cache[s[j]]++;
            
            auto maxKey = max_element(cache.begin(), cache.end(), [](auto& a, auto& b)
                                     {
                                        return a.second < b.second; 
                                     });
            
            int windowSize = j-i+1;
            if(windowSize - maxKey->second <= k)
            {
                j++;
                maxLen = max(maxLen, windowSize);
            }
            else
            {
                cache[s[i]]--;
                i++;
                j++;
            }
        }
        
        return maxLen;
    }
};