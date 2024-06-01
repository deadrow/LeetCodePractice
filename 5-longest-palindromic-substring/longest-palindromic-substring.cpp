class Solution {
public:
    string longestPalindrome(string s) {
        // Palindrom strings have center, left and right
        // in case of odd length and 2 centers in case
        // of event length
        int n = s.size();
        int i=0;
        int k=0;
        int longest=0;
        string res;
        for(int j=0;j<n;j++){
            int i=j;
            int k=j;
            while(i>=0 and k<n and s[i]==s[k]){
                if(k-i+1 > longest){
                    longest = k-i+1;
                    res = s.substr(i, longest);
                }
                i--;
                k++;
            }

            i=j;
            k=j+1;
            while(i>=0 and k<n and s[i]==s[k]){
                if(k-i+1 > longest){
                    longest = k-i+1;
                    res = s.substr(i, longest);
                }
                i--;
                k++;
            }
        }
        return res;
    }
};