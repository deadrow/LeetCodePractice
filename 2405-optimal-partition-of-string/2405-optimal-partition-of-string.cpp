class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        set<char>dict;
        
        for(int i=0;i<s.size();i++)
        {
            if(dict.find(s[i]) == dict.end())
            {
                dict.insert(s[i]);
                continue;
            }
            else
            {
                count++;
                dict.clear();
                dict.insert(s[i]);
            }
        }
        
        return count+1;
    }
};