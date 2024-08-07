class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int maxLen=0;
        unordered_set<string>mp;
        for(int i=0;i<s.size();i++){
            string st(1, s[i]);
            if(mp.count(st)) maxLen = max(maxLen, (int)st.size());
            else mp.insert(st);
            for(int j=i+1;j<s.size();j++){
                st += s[j];
                if(mp.count(st)) maxLen = max(maxLen, (int)st.size());
                else mp.insert(st);
            }
        }
        return maxLen;
    }
};