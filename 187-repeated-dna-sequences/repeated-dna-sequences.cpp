class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};

        vector<string>ret;
        unordered_map<string,int>dict;
        int rollingHash=0;
        for(int j=0;j<=s.size()-10;j++){
            string cur = s.substr(j, 10);
            dict[cur]++;
            if(dict[cur] == 2)
                ret.push_back(cur);
        }

        return ret;
    }
};