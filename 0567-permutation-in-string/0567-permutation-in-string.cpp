class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        size_t s1Hash = 0;
        size_t s2Hash = 0;
        
        for(int i=0;i<s1.size();i++)
        {
            int val = s1[i] - 'a' + 1;
            s1Hash += val*val*val*val;
        }
        
        int i=0;
        int j=0;
        int k = s1.size();
        while(j < s2.size())
        {
            int val = s2[j] - 'a' + 1;
            s2Hash += val*val*val*val;
            
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                if(s1Hash == s2Hash)
                    return true;
                
                // calculate rolling hash
                // start removing last element
                int iVal = s2[i] - 'a' + 1;
                s2Hash -= iVal*iVal*iVal*iVal;
                
                j++;
                i++;
            }
        }
        
        return false;
    }
};