class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, vector<int>>mp;
        for(int i=0;i<votes[0].size();i++)
            mp[votes[0][i]] = vector<int>(votes[0].size()+1);

        for(auto word : votes){
            for(int i=0;i<word.size();i++){
                mp[word[i]][i+1]++;
            }
        }

        string ret = votes[0];
        sort(ret.begin(), ret.end(), [&](const auto& a, const auto& b){
            return mp[a] == mp[b] ? a < b : mp[a] > mp[b];
        });
        return ret;
    }
};