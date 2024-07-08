class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int>dict;
        int i=0;
        int maxLen=INT_MIN;
        for(int j=0;j<s.size();j++){
            dict[s[j]]++;
            if(dict.size() <= 2){
                maxLen = max(maxLen, j-i+1);
            } else if(dict.size() > 2){
                dict[s[i]]--;
                if(dict[s[i]] == 0)
                    dict.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }
};