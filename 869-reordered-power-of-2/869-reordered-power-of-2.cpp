class Solution {
public:
    bool powerOfTwo = false;
    void permute(string s, int cur_i)
    {
        if(cur_i == s.size())
        {
            if(s[0] != '0')
            {
                int ret = stoi(s);
                if((ret & (ret-1)) == 0)
                    powerOfTwo = true;
            }

            return;
        }
        else
        {
            for(int i=cur_i;i<s.size();i++)
            {
                swap(s[i], s[cur_i]);
                permute(s, cur_i+1);
                swap(s[i], s[cur_i]);
            }
        }
    }
    bool reorderedPowerOf21(int n) {
        string cur = to_string(n);
        permute(cur, 0);
        return powerOfTwo;
    }
    
    bool reorderedPowerOf2(int n) {
        string cur = to_string(n);
        int digits[10] = {0};
        
        for(auto it : cur)
            digits[it-'0']++;
        
        for(int i=0;i<31;i++)
        {
            string next = to_string(1<<i);
            int curDigits[10] = {0};
            for(auto it : next)
                curDigits[it-'0']++;
            
            bool matched = true;
            for(int i=0;i<10;i++)
            {
                if(curDigits[i] != digits[i])
                {
                    matched = false;
                    break;
                }
            }
            
            if(matched)
                return true;
        }
        
        return false;
    }
};