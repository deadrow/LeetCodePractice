class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int>dict;
        int i=0;
        int maxLen=0;
        for(int j=0;j<s.size();j++){
            dict[s[j]]++;
            if(dict.size() <= k){
                maxLen = max(maxLen, j-i+1);
            } else if(dict.size() > k){
                dict[s[i]]--;
                if(dict[s[i]] == 0)
                    dict.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }
};