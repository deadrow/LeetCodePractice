class Solution {
public:
    int countDistinct(string s) {
        unordered_set<string>mp;
        for(int i=0;i<=s.size();i++){
            for(int j=i+1;j<=s.size();j++){
                mp.insert(s.substr(i,j-i));
            }
        }
        return mp.size();
    }
};