class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>pCount(26), sCount(26);
        for(auto it : p) pCount[it-'a']++;
        int i=0;
        vector<int> ret;
        for(int j=0;j<s.size();j++){
            sCount[s[j]-'a']++;
            if(j-i+1 == p.size()){
                if(pCount == sCount)
                    ret.push_back(i);
                sCount[s[i]-'a']--;
                i++;
            }
        }
        return ret;
    }
};