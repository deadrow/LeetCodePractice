class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string ret = countAndSay(n-1);
        int count=1;
        char prev=ret[0];
        
        string newString;
        for(int i=1;i<ret.size();i++)
        {
            if(ret[i] != prev)
            {
                newString += to_string(count) + prev;
                prev = ret[i];
                count = 1;
            }
            else
            {
                count++;
            }
        }
        
        newString += to_string(count) + prev;
        return newString;
    }
};