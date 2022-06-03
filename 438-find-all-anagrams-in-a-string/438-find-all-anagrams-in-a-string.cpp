class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        
        size_t sHash = 0;
        size_t pHash = 0;
        
        for(int i=0;i<p.size();i++)
        {
            int sVal = s[i] - 'a' + 1;
            int pVal = p[i] - 'a' + 1;
            
            // sHash += sVal*sVal*sVal;
            pHash += pVal*pVal*pVal;
        }
        
        // if(sHash == pHash)
        //     ret.push_back(0);
        
        int i=0;
        int j=0;
        int k = p.size();
        while(j < s.size())
        {
            int sVal = s[j] - 'a' + 1;
            sHash += sVal*sVal*sVal;
            
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                if(sHash == pHash)
                    ret.push_back(i);
                
                int iVal = s[i] - 'a' + 1;
                sHash -= iVal*iVal*iVal;
                
                j++;
                i++;
            }
        }
        
        return ret;
    }
};