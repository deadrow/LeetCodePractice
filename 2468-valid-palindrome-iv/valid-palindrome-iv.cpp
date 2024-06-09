class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    bool makePalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        int count = 0;
        while(i<j){
            if(s[i] != s[j]) {
                count++;
                if(count > 2) return false;
            }
            i++; j--;
        }
        return true;
    }
};