class Solution {
public:
    vector<vector<int>> memo;
    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
    int count(int n, char last)
    {
        if(n == 0)
            return 1;
        
        if(memo[n][last] != -1)
            return memo[n][last];
        
        int ans = 0;
        for(auto it : vowels)
        {
            if(it >= last)
                ans += count(n-1, it);
        }
        return memo[n][last] = ans;
    }
    
    int countVowelStrings(int n) {
        memo.resize(n+1, vector<int>('u'+1,-1));
        
        int ans = 0;
        for(auto it : vowels)
        {
            ans += count(n-1, it);
        }
        
        return ans;
    }
};