class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> cache;
        
        int i=0;
        int j=0;
        int maxLen = 0;
        int maxKeyCount = 0;
        while(j < s.size())
        {
            cache[s[j]]++;
            maxKeyCount = max(maxKeyCount, cache[s[j]]);
            
            // auto maxKey = max_element(cache.begin(), cache.end(), [](auto& a, auto& b)
            //                          {
            //                             return a.second < b.second; 
            //                          });
            
            // LOGIC Find the key with max count in map
            // and remove that from window size. The
            // remaining value should be the chars which
            // we can change to make the key with max count
            // more bigger.
            int windowSize = j-i+1;
            if(windowSize - maxKeyCount <= k)
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