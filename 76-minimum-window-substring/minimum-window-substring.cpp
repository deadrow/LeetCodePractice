class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>remaining;
        for(auto it : t) remaining[it]++;

        int count=t.size();
        int minWindow = INT_MAX;
        int i=0,j=0;
        int idx=-1;
        for(;j<s.size();j++){
            if(remaining[s[j]] > 0)
                count--;

            remaining[s[j]]--; // chars which are present in s but not in t so it would be negative

            if(count == 0){
                // shrink window till count is 0
                while(count == 0) {
                    // we found one window
                    // save and find smaller
                    if(j-i+1 < minWindow){
                        minWindow = j-i+1;
                        idx = i;
                    }
                    
                    remaining[s[i]]++;
                    if(remaining[s[i]] > 0)
                        count++;
                    i++;
                }
            }
        }

        return minWindow == INT_MAX ? "" : s.substr(idx, minWindow);
    }
};