class Solution {
public:
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