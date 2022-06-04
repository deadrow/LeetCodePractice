class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        
        unordered_map<char, int> cache;
        for(auto it : t)
            cache[it]++;
        
        int count = cache.size();
        
        int i=0;
        int j=0;
        int idx = -1;
        int minLen = INT_MAX;

        while(j < s.size())
        {
            // calculation
            if(cache.find(s[j]) != cache.end())
            {
                cache[s[j]]--;
                if(cache[s[j]] == 0)
                    count--;
            }
            
            if(count > 0)
            {
                j++;
            }
            else if(count == 0)
            {
                if(minLen > j-i+1)
                {
                    minLen = j-i+1;
                    idx = i;
                }
                
                // shrink i to find min window
                while(count == 0)
                {
                    if(cache.find(s[i]) != cache.end())
                    {
                        cache[s[i]]++;
                        if(cache[s[i]] > 0)
                        {
                            count++;
                            i++;
                        }
                        else
                        {
                            i++;
                            if(minLen > j-i+1)
                            {
                                minLen = j-i+1;
                                idx = i;
                            }
                        }
                    }
                    else
                    {
                        i++;
                        if(minLen > j-i+1)
                        {
                            minLen = j-i+1;
                            idx = i;
                        }
                    }
                }
                
                j++;
            }
        }
        
        if(idx == -1)
            return "";
        
        return s.substr(idx, minLen);
    }
};