class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>dict;
        for(auto it : s) dict[it]++;

        bool oneOdd = false;
        int ret = 0;
        for(auto it : dict){
            if((it.second & 1) == 0)
                ret += it.second;
            else {
                oneOdd = true;
                ret += it.second-1;
            }
        }
        return oneOdd ? ret+1 : ret;
    }
};