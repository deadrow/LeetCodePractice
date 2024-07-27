class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>ret;
        for(auto it : words){
            stringstream ss(it);
            string token;
            while(getline(ss, token, separator)){
                if(!token.empty()) ret.push_back(token);
            }
        }
        return ret;
    }
};