class Solution {
public:
    map<char, int> sHash;
    int romanToInt(string s)
    {
        if(sHash.empty())
        {
            sHash['I'] = 1;
            sHash['V'] = 5;
            sHash['X'] = 10;
            sHash['L'] = 50;
            sHash['C'] = 100;
            sHash['D'] = 500;
            sHash['M'] = 1000;
        }
        
        int index = 0;
        int result = 0;
        while(index < s.length())
        {
            int currentNum = sHash[s[index]];
            int nextNum = (index+1 < s.length()) ? sHash[s[index+1]] : 0;
            
            if(nextNum > currentNum)
            {
                result += nextNum - currentNum;
                index += 2;
            }
            else
            {
                result += currentNum;
                index++;
            }
        }
        
        return result;
    }
};