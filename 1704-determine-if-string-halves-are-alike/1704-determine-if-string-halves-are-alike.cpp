class Solution {
public:
    bool halvesAreAlike(string s) {
        multiset<char>first;
        multiset<char>second;
        
        string vowels("aeiouAEIOU");
        
        for(int i=0;i<s.size()/2;i++)
        {
            if(vowels.find(s[i]) != string::npos)
                first.insert(s[i]);
        }
        
        for(int i=s.size()/2;i<s.size();i++)
        {
            if(vowels.find(s[i]) != string::npos)
                second.insert(s[i]);
        }
        
        if(first.size() != second.size())
            return false;

        return true;
            
    }
};