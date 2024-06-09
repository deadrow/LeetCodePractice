class Solution {
public:
    // 1st approach
    unordered_map<string, int> dict;
    bool palindrome(string& s, int i, int j, int k){
        if(k<0) return false;
        if(i > j) return true;

        string key = to_string(i) + "#" + to_string(j)+ "#" + to_string(k);
        if(dict.count(key)) return dict[key];
        if(s[i] == s[j])
            return dict[key]=palindrome(s, i+1, j-1, k);
        return dict[key] = (palindrome(s, i+1, j, k-1) || palindrome(s, i, j-1, k-1));
    }
    bool isValidPalindrome1(string s, int k) {
        int n = s.size();
        return palindrome(s, 0, s.size()-1, k);
    }

    // Second approach. Find Longest common subsequence of
    // string and reverse string. If lcs is x and x +k >= len(s)
    // return true;
    vector<vector<int>>memo;

    // top down with memoization
    int lcs(string& s1, string& s2, int i, int j)
    {
        if(i < 0 || j < 0)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];

        if(s1[i] == s2[j])
            return memo[i][j] = 1 + lcs(s1, s2, i-1, j-1);
        return memo[i][j] = max(lcs(s1, s2, i-1, j), lcs(s1, s2, i, j-1));
    }

    bool isValidPalindrome2(string s, int k) {
        string rev(s);
        reverse(rev.begin(), rev.end());

        memo.resize(s.size(), vector<int>(s.size(), -1));
        return lcs(s, rev, s.size()-1, s.size()-1) + k >= s.size();
    }

    // 3rd approach
    int minReplaces(string& s, int i, int j) {
        if(i > j) return 0;

        if(memo[i][j] != -1)
            return memo[i][j];

        if(s[i] == s[j])
            return memo[i][j] = minReplaces(s, i+1, j-1);
        return memo[i][j] = 1 + min(minReplaces(s, i+1, j) , minReplaces(s, i, j-1));
    }

    bool isValidPalindrome(string s, int k) {
        // Find min deletes to make string pallindrom
        memo.resize(s.size(), vector<int>(s.size(), -1));
        return minReplaces(s, 0, s.size()-1) <=k;
    }
};