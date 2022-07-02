class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int m = s.size();
        int ans = 0;
        
        unordered_map<char, vector<int>> cache;
        for(int i=0;i<s.size();i++)
            cache[s[i]].push_back(i);
        
        for(auto it : words)
        {
            auto word = it;
            
            int x = -1;
            bool found = true;
            for(auto c : word)
            {
                auto c_it = upper_bound(cache[c].begin(), cache[c].end(), x);
                if(c_it == cache[c].end())
                    found = false;
                else
                    x = *c_it;
            }
            
            if(found)
                ans++;
        }
        
        return ans;
    }
};