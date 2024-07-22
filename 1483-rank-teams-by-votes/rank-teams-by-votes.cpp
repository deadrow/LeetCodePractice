class Solution {
public:
    string rankTeams(vector<string>& votes) {
        // Main logic is to compare 2 vectors
        // For e.g {5,0,0} is > than {2,3,3}
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