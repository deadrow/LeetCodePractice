class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // This question is marked easy but it is
        // kind of medium
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i] != s[j]) {
                // If chars doesn't match
                // check by deleting i first or
                // check by deleting j
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
            i++; j--;
        }
        return true;
    }
};