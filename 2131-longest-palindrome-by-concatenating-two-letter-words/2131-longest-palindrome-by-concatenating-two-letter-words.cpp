class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>dict;
        
        for(auto it : words)
            dict[it]++;
        
        int count = 0;
        bool used = false;
        for(auto it : dict)
        {
            string cur = it.first;
            string rev{cur[1], cur[0]};
            if(cur == rev)
            {
                int freq = dict[cur];
                if(!used && freq & 1)
                {
                    used = true;
                    count += (freq/2)*4 + 2;
                }
                else
                    count += (freq/2)*4;
                    
            }
            else if(dict.find(rev) != dict.end())
                count += min(dict[cur], dict[rev])*2;            
        }
        
        return count;
    }
};