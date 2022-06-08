class Solution {
public:
    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
    int count(int n, char last)
    {
        if(n == 0)
            return 1;
        
        int ans = 0;
        for(auto it : vowels)
        {
            if(it >= last)
                ans += count(n-1, it);
        }
        return ans;
    }
    
    int countVowelStrings(int n) {
        int ans = 0;
        for(auto it : vowels)
        {
            ans += count(n-1, it);
        }
        
        return ans;
    }
};