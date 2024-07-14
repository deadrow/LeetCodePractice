class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string>tokens;
        string token;
        while(getline(ss, token, ' ')){
            tokens.push_back(token);
        }

        if(tokens.size() != pattern.size()) return false;

        unordered_map<char, string>cToW;
        unordered_map<string, char>wToC;
        for(int i=0;i<pattern.size();i++){
            if(cToW.count(pattern[i])){
                if(wToC.count(cToW[pattern[i]]) and tokens[i] != cToW[pattern[i]])
                    return false;
            }
            if(wToC.count(tokens[i]) and wToC[tokens[i]] != pattern[i])
                return false;
            cToW[pattern[i]] = tokens[i];
            wToC[tokens[i]] = pattern[i];
        }
        return true;
    }
};