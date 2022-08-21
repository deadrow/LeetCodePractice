class Solution {
public:
    bool isMatch(string& a, string& b)
    {
        if(a.size() != b.size())
            return false;
        
        for(int i=0;i<a.size();i++)
        {
            if(a[i] != b[i] && a[i] != '?' && b[i] != '?')
                return false;
        }
        
        return true;
    }
    
    bool allWildCards(string& a)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i] != '?')
                return false;
        }
        
        return true;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size();
        int n = target.size();
        
        vector<int> ret;
        
        while(true)
        {
            // Find atleaset 1 match otherwise break the loop
            bool matchFound = false;
            for(int i=0;i<n-m+1;i++)
            {
                string cur = target.substr(i, m);

                if(allWildCards(cur))
                    continue;
                
                if(isMatch(stamp, cur))
                {
                    matchFound = true;
                    ret.push_back(i);

                    for(int j=0;j<m;j++)
                        target[i+j] = '?';
                }
            }
            
            if(!matchFound)
                break;
        }
        
        // still some char left
        if(!allWildCards(target)) return vector<int>();
        
        reverse(ret.begin(), ret.end());
        
        return ret;

    }
};