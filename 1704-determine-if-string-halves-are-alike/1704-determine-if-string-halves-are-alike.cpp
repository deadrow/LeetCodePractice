class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char>first;
        vector<char>second;
        
        string vowels("aeiouAEIOU");
        
        for(int i=0;i<s.size()/2;i++)
        {
            if(vowels.find(s[i]) != string::npos)
                first.push_back(s[i]);
        }
        
        for(int i=s.size()/2;i<s.size();i++)
        {
            if(vowels.find(s[i]) != string::npos)
                second.push_back(s[i]);
        }
        
        if(first.size() != second.size())
            return false;

        return true;
            
    }
};