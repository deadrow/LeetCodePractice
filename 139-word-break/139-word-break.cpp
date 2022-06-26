class Solution {
public:
    unordered_set<string> dict;
    vector<int> memo;
    bool dp(string s, int start)
    {
        if(start >= s.size())
            return true;
        
        if(memo[start] != -1)
            return memo[start];
        
        for(int i=start+1;i<=s.size();i++)
        {
            string first = s.substr(start,i-start);
            if(dict.find(first) != dict.end() && dp(s, i))
                return memo[start] = 1;
        }
        return memo[start] = 0;
        
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        memo.resize(s.size(),-1);
        dict.insert(wordDict.begin(), wordDict.end());
        
        return dp(s, 0);
    }
};