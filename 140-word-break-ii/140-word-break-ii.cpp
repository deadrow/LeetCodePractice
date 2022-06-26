class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;
        
    vector<string> dp(string& s, int start)
    {
        vector<string> res;
        if(start == s.size())
        {
            res.push_back("");
            return res;
        }

        if(memo.find(start) != memo.end())
            return memo[start];
            
        for(int i=start+1;i<=s.size();i++)
        {
            string first = s.substr(start, i-start);
            if(dict.find(first) != dict.end())
            {
                vector<string> sentences = dp(s, i);
                for(auto it : sentences)
                {
                    res.push_back(first + (it == "" ? "" : " ") + it);
                }
            }
        }
        
        return memo[start] = res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict.insert(wordDict.begin(), wordDict.end());
        return dp(s, 0);
    }
};