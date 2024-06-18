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
    bool wordBreak1(string s, vector<string>& wordDict) {
        // First approach with dp where we take first half
        // and then recursively check for second half. Once
        // we that both are present in dict then we return true
        // we memoized to prevent TLE
        for(auto it : wordDict){
            dict.insert(it);
        }
        return dp(s);
    }

    vector<int>memo1;
    bool dp(string& s, int i){
        if(i >= s.size()) return true;

        if(memo1[i] != -1) return memo1[i];
        for(int cur=i+1;cur<=s.size();cur++){
            string first = s.substr(i, cur-i);
            cout << first << endl;
            if(dict.count(first) && dp(s, cur)) return memo1[i]=true;
        }
        return memo1[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // Second approach is to pass the starting index
        // of string in the recursion so that we can optimise
        for(auto it : wordDict){
            dict.insert(it);
        }
        memo1.resize(s.size()+1, -1);
        return dp(s, 0);
    }
};