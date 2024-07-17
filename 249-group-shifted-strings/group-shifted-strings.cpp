class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>>ret;
        unordered_map<string, multiset<string>>mp;
        for(auto word : strings){
            char first = word[0];
            // Find out hash of string for "abc" it would be "a12"
            string hash="a";
            for(int i=1;i<word.size();i++){
                hash += (word[i]-first+26)%26 + 'a';
            }
            mp[hash].insert(word);
        }
        for(auto it : mp){
            ret.push_back(vector<string>(it.second.begin(), it.second.end()));
        }
        return ret;
    }
};