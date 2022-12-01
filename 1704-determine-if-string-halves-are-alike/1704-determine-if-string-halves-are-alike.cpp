class Solution {
public:
    bool halvesAreAlike(string s) {
        int first=0;
        int second=0;
        
        string vowels("aeiouAEIOU");
        
        for(int i=0, j=s.size()/2;i<s.size()/2;i++,j++)
        {
            if(vowels.find(s[i]) != string::npos)
                first++;
            if(vowels.find(s[j]) != string::npos)
                second++;
        }

        return first == second;
    }
};