class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int>remaining;
        for(auto it : t) remaining[it]++;

        int count=remaining.size();
        int minWindow = INT_MAX;
        int i=0,j=0;
        int idx=-1;
        string ret;
        for(;j<s.size();j++){
            if(remaining.count(s[j])){
                 remaining[s[j]]--; // negative remain value indicates that we have more than we need
                 if(remaining[s[j]] == 0)
                    count--;
            }

            if(count == 0){
                // shrink window till count is 0
                while(count == 0)
                {
                    // we found one window
                    // save and find smaller
                    if(j-i+1 < minWindow){
                        minWindow = j-i+1;
                        idx = i;
                    }
                    if(remaining.count(s[i])){
                        remaining[s[i]]++;
                        if(remaining[s[i]]> 0)
                            count += remaining[s[i]];
                    }
                    i++;
                }
            }
        }

        return idx ==-1 ? "" : s.substr(idx, minWindow);
    }
};