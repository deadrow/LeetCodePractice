class Solution {
public:
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
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        return palindrome(s, 0, s.size()-1, k);
    }
};