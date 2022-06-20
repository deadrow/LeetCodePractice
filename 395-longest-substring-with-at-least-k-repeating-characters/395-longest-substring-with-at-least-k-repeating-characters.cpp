class Solution {
public:
    int longestSubstring(string s, int k) {
        // divide and concur approach
        
        int n = s.size();
        if(k <= 1)
            return n;
        
        unordered_map<char, int> mp;
        for(auto it : s)
            mp[it]++;
        
        int left_i = 0;
        
        // break when < k char found
        while(left_i < n && mp[s[left_i]] >= k)
            left_i++;
        
        if(left_i == n)
            return n;
        
        int left = longestSubstring(s.substr(0, left_i), k);
        
        while(left_i < n && mp[s[left_i]] < k)
            left_i++;
        
        int right = longestSubstring(s.substr(left_i), k);
        
        return max(left, right);
    }
};