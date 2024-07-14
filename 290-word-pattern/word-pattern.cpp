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

        unordered_map<char, string>charToWord;
        unordered_map<string, char>wordToChar;
        for(int i=0;i<pattern.size();i++){
            if(charToWord.count(pattern[i])){
                if(wordToChar.count(charToWord[pattern[i]]) and tokens[i] != charToWord[pattern[i]])
                    return false;
            }
            if(wordToChar.count(tokens[i]) and wordToChar[tokens[i]] != pattern[i])
                return false;
            charToWord[pattern[i]] = tokens[i];
            wordToChar[tokens[i]] = pattern[i];
        }
        return true;
    }
};