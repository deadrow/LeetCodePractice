class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            while(i<j and !isalnum(s[i])) i++;
            while(j>i and !isalnum(s[j])) j--;
            if(tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};