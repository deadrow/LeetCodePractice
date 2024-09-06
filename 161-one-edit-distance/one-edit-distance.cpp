class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int i=0,j=0;
        while(i<s.size() or j<t.size()){
            if(i==s.size()) return t.substr(j).size() == 1;
            if(j==t.size()) return s.substr(i).size() == 1;
            if(s[i]==t[j]){
                i++,j++;
            } else if(s[i]!=t[j]) {
                if((s.substr(i+1) == t.substr(j)) or (s.substr(i) == t.substr(j+1)) or s.substr(i+1)==t.substr(j+1))
                    return true;
                else return false;
            }
        }
        return false;
    }
};