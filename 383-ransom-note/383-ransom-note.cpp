class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>dict;
        for(auto it : magazine)
            dict[it]++;
        
        for(auto it : ransomNote)
        {
            if(dict.find(it) == dict.end())
                return false;
            
            if(dict[it] == 0)
                return false;
            
            dict[it]--;
        }
            
        return true;
    }
};