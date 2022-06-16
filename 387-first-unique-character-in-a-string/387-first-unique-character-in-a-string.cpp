class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i]) != mp.end())
                mp[s[i]] = -1;
            else
                mp[s[i]] = i;
        }
        
        int min_i = s.size()+2;
        for(auto it : mp)
        {
            if(it.second != -1)
                min_i = min(it.second, min_i);
        }
        
        return min_i == s.size()+2 ? -1 : min_i;
    }
};