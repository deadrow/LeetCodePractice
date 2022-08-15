class Solution {
public:
    string removeDigit(string number, char digit) {
        
        string maxString;
        for(int i=0;i<number.size();i++)
        {
            if(number[i] != digit)
                continue;
            
            string newString = number.substr(0, i) + number.substr(i+1);
            if(newString > maxString)
                maxString = newString;
        }
        
        return maxString;
    }
};