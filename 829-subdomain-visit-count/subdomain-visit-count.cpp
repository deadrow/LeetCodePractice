class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>mp;
        for(auto& cp : cpdomains){
            int idx = cp.find(" ");
            int count = stoi(cp.substr(0, idx));
            string word = cp.substr(idx+1);
            mp[word] += count;
            for(int i=0;i<word.size();i++){
                if(word[i] == '.'){
                    mp[word.substr(i+1)] += count;
                }
            }
        }

        vector<string> ret;
        for(auto it : mp){
            ret.push_back(to_string(it.second) + " " + it.first);
        }
        return ret;
    }
};