class Solution {
public:
    vector<string> ret;
    unordered_set<string>dict;
    void backtrack(string& s, int i, string cur) {
        if(i >= s.size()) {
            cur.pop_back();
            ret.push_back(cur);
            return;
        }
        for(int start=i+1;start<=s.size();start++){
            string first = s.substr(i, start-i);
            if(dict.count(first)) {
                cur += first + " ";
                backtrack(s, start, cur);
                cur.erase(cur.size()- (first.size() +1));
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it : wordDict)
            dict.insert(it);
        string cur;
        backtrack(s, 0, cur);
        return ret;
    }
};