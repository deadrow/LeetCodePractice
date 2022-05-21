class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        
        int pow_idx = 0;
        for(int i=columnTitle.size()-1;i>=0;i--)
        {
            res += pow(26, pow_idx++) * (columnTitle[i]- 64);
        }
        
        return res;
    }
};