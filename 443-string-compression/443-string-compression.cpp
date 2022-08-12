class Solution {
public:
    int compress(vector<char>& chars) {
        string res;
        if(chars.empty())
            return 0;
        
        if(chars.size() == 1)
            return 1;
        
        int n = chars.size();
        int count = 1;
        char lastChar;
        for(int i=1;i<n;i++)
        {
            if(chars[i] != chars[i-1])
            {
                lastChar = chars[i];
                if(count != 1)
                    res += chars[i-1] + to_string(count);
                else
                    res += chars[i-1];
                
                count = 1;
            }
            else
                count++;
        }
        
        if(count == 1)
            res += chars[n-1];
        else
            res += chars[n-1] + to_string(count);
        
        chars.clear();
        for(auto it : res)
            chars.push_back(it);
        
        return res.size();
    }
};