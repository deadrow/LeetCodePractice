class Solution {
public:
    unordered_map<char, vector<char>>mp{
        {'a',{'e'}}, 
        {'e', {'a','i'}},
        {'i', {'a','e','o','u'}},
        {'o', {'i', 'u'}},
        {'u',{'a'}}
    };
    vector<vector<int>>memo;
    int MOD = 1e9+7;
    int dp(int n, char cur){
        if(n==0) return 1;
        if(memo[n][cur-'a'] != -1) return memo[n][cur-'a'];
        int count=0;
        for(const auto& it : mp[cur])
            count = (count + dp(n-1, it)) % MOD;
        return memo[n][cur-'a'] = count;
    }
    int countVowelPermutation(int n) {
        memo.resize(n+1,vector<int>('z'-'a'+1, -1));
        int count=0;
        for(const auto& it : mp)
            count = (count + dp(n-1, it.first)) % MOD;
        return count;
    }
};