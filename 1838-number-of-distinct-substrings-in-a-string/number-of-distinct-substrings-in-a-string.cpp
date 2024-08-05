class Solution {
public:
    int countDistinct(string s) {
        unordered_set<string>mp;
        for(int i=0;i<s.size();i++){
            string st(1,s[i]);
            mp.insert(st);
            for(int j=i+1;j<s.size();j++){
                st += s[j];
                mp.insert(st);
            }
        }
        return mp.size();
    }
};