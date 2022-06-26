class Solution {
public:
    vector<string> ret;
    unordered_set<string> dict;
    
    string join(const vector<string>& strings)
    {
        string ret;
        int n = strings.size();
        for(int i=0;i<n;i++)
        {
            ret += strings[i];
            if(i != n-1)
                ret += " ";
        }
        
        return ret;
    }
    
    void dp(string& s, int start, vector<string>& cur)
    {
        if(start == s.size())
        {
            ret.push_back(join(cur));
        }

        for(int i=start+1;i<=s.size();i++)
        {
            string first = s.substr(start,i-start);
            if(dict.find(first) != dict.end())
            {
                cur.push_back(first);
                dp(s, i, cur);
                cur.pop_back();
            }
        }        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict.insert(wordDict.begin(), wordDict.end());
        
        vector<string> cur;
        dp(s, 0, cur);
        return ret;
    }
};