class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        unordered_map<string,int>dict;
        int rollingHash=0;
        for(int j=0;j<=s.size()-10;j++){
            dict[s.substr(j, 10)]++;
        }

        vector<string>ret;
        for(auto it : dict){
            if(it.second>1)
                ret.push_back(it.first);
        }
        return ret;
    }
};