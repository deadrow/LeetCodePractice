class Solution {
public:
    bool halvesAreAlike(string s) {
        // unordered_map<char, int> first;
        // unordered_map<char, int> second;
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
        
//         for(auto it : first)
//         {
//             if(second.find(it.first) == second.end())
//                 return false;
            
//             if(it.second != second[it.first])
//                 return false;
//         }
        
        return true;
            
    }
};