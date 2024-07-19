class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(auto& it : strs){
            vector<int>count(26);
            for(auto& c : it)
                count[c-'a']++;
            string s;
            for(int i=0;i<26;i++){
                if(count[i]!=0){
                    char key = 'a'+i;
                    char val = '0'+count[i];
                    s.append(1, key).append(1,val);
                }
            }
            mp[s].push_back(it);
        }

        vector<vector<string>> ret;
        for(auto& it : mp){
            ret.push_back(it.second);
        }
        return ret;
    }
};