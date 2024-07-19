class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>common(26);
        for(char c : words[0])
            common[c-'a']++;
        for(int i=1;i<words.size();i++){
            vector<int>cur(26);
            for(char c : words[i]){
                cur[c-'a']++;
            }
            for(int i=0;i<26;i++){
                common[i] =min(common[i], cur[i]);
            }
        }
        vector<string> ret;
        for(int i=0;i<26;i++){
            while(common[i]--)
                ret.push_back(string(1, i+'a'));
        }
        return ret;
    }
};