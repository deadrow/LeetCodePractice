class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, vector<int>>mp;
        for(auto& c : votes[0])
            mp[c] = vector<int>(votes[0].size());

        for(auto& word : votes){
            for(int i=0;i<word.size();i++){
                mp[word[i]][i]++;
            }
        }

        string ret = votes[0];
        sort(ret.begin(), ret.end(), [&](const auto& a, const auto& b){
            return mp[a] == mp[b] ? a < b : mp[a] > mp[b];
        });
        return ret;
    }
};