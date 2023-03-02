class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int i = 0;
        int ret = 0;
        
        while(i<n)
        {
            int groupLen = 1;
            while(i+groupLen < n && chars[i] == chars[i+groupLen])
                groupLen++;
            
            chars[ret++] = chars[i];
            if(groupLen > 1)
            {
                for(auto it : to_string(groupLen))
                    chars[ret++] = it;
            }
            i += groupLen;
        }
        
        return ret;
    }
};