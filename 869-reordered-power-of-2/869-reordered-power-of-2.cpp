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
    bool reorderedPowerOf2(int n) {
        string cur = to_string(n);
        permute(cur, 0);
        return powerOfTwo;
    }
};