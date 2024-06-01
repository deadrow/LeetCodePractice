class Solution {
public:
    string longestPalindrome1(string s) {
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

    string longestPalindrome(string s) {
        // dp solution
        // for s = "babad" we check if smaller string is
        // palindrome like aba and then converge to b
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n));
        int start = 0;
        int end = 0;

        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++){
                dp[i][j] = s[i]==s[j] && (j-i<=2 or dp[i+1][j-1]);
                if(dp[i][j] && j-i > end-start) { // if we found new string after expanding true 
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};