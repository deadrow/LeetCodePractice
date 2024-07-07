class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1) return "";

        for(int i=0;i<n;i++){
            string temp = palindrome;
            if(temp[i] != 'a')
                temp[i] = 'a';
            string rev = temp;
            reverse(rev.begin(), rev.end());
            if(temp != rev) return temp;
        }

        palindrome[n-1] = 'b';
        return palindrome;
    }
};