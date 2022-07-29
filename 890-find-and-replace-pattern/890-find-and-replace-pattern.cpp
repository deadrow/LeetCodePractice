class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for(auto it : words)
        {
            map<char, char> charToPat;
            map<char, char> patToChar;
            string word = it;
            bool match = true;
            for(int i=0;i<word.size();i++)
            {
                if(patToChar.find(pattern[i]) != patToChar.end())
                {
                    if(patToChar[pattern[i]] != word[i])
                        match = false;
                }
                else if(charToPat.find(word[i]) != charToPat.end())
                {
                    match = false;
                }
                else
                {
                    patToChar[pattern[i]] = word[i];
                    charToPat[word[i]] = pattern[i];
                }
            }
            
            if(match)
                res.push_back(word);
        }
        
        return res;
    }
};