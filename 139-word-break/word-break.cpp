class Solution {
public:
    unordered_set<string>dict;
    unordered_map<string, bool>memo;
    bool dp(string& s){
        if(s.empty() || dict.count(s)) return true;

        if(memo.count(s)) return memo[s];

        for(int i=0;i<s.size();i++){
            string first = s.substr(0, i);
            string next = s.substr(i);
            if(dict.count(first) && dp(next)) return memo[s]=true;
        }
        return memo[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it : wordDict){
            dict.insert(it);
        }
        return dp(s);
    }
};