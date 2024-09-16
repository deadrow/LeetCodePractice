class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lower(26),upper(26);
        for(auto it : word){
            if(islower(it)) lower[it-'a']++;
            else upper[it-'A']++;
        }
        int count=0;
        for(int i=0;i<26;i++)
            count += lower[i] and upper[i];
        return count;
    }
};