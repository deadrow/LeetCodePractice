class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char>first;
        vector<char>second;
        
        string vowels("aeiouAEIOU");
        
        for(int i=0, j=s.size()/2;i<s.size()/2;i++,j++)
        {
            if(vowels.find(s[i]) != string::npos)
                first.push_back(s[i]);
            if(vowels.find(s[j]) != string::npos)
                second.push_back(s[j]);
        }

        if(first.size() != second.size())
            return false;

        return true;
            
    }
};