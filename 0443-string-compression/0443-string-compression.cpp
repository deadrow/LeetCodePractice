class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        vector<char> temp;
        
        int curCount = 0;
        for(int i=0;i<n;i++)
        {
            if(i == 0 || chars[i-1] == chars[i])
                curCount++;
            else
            {
                temp.push_back(chars[i-1]);
                if(curCount > 1)
                {
                    if(curCount < 10)
                        temp.push_back(curCount + '0');
                    else
                    {
                        string num = to_string(curCount);
                        for(auto it : num)
                            temp.push_back(it);
                    }
                }
 
                curCount = 1;
            }
        }
        
        if(curCount)
        {
            temp.push_back(chars[n-1]);
            if(curCount > 1)
            {
                if(curCount < 10)
                    temp.push_back(curCount + '0');
                else
                {
                    string num = to_string(curCount);
                    for(auto it : num)
                        temp.push_back(it);
                }
            }
        }
        
        chars.clear();
        chars = temp;
        return chars.size();
    }
};