class Solution {
public:
    string removeDigit(string number, char digit) {
        set<string, greater<>> dict;
        
        for(int i=0;i<number.size();i++)
        {
            if(number[i] != digit)
                continue;
            
            string newString = number.substr(0, i) + number.substr(i+1);
            dict.insert(newString);
        }
        
        return *dict.begin();
    }
};