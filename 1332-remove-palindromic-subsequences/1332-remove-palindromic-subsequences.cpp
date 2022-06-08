class Solution {
public:
    int removePalindromeSub(string s) {
        string reverse(s.rbegin(), s.rend());
        
        if(reverse == s)
            return 1;
        
        return 2;
    }
};