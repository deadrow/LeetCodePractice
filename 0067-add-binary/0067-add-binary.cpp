class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        
        string res;
        int carry = 0;
        while(i >=0 || j >= 0)
        {
            if(i >= 0)
                carry += a[i--] - '0';
            
            if(j >=0)
                carry += b[j--] - '0';

            if(carry < 2)
            {
                res += carry + '0';
                carry = 0;
            }
            else
            {
                if(carry == 3)
                    res += '1';
                else
                    res += '0';
                carry = 1;
            }
        }
        
        if(carry == 1)
            res += '1';
        
        reverse(res.begin(), res.end());
        return res;
    }
};