class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int dict[26] = {0};
        for(auto it : magazine)
            dict[it-'a']++;
        
        for(auto it : ransomNote)
        {            
            if(dict[it-'a'] == 0)
                return false;
            
            dict[it-'a']--;
        }
            
        return true;
    }
};