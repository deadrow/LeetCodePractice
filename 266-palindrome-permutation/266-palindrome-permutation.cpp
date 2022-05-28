class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> cache;
        for(auto it : s)
        {
            cache[it]++; 
        }
        
        int odd = 0;
        for(auto it : cache)
        {
            if(it.second & 1)
                odd++;
        }
        
        return odd <=1;
    }
};