class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ret;
        
        int i = num.size()-1;
        int carry = 0;
        while(i>=0 || k)
        {
            
            if(i >= 0)
            {
                carry += num[i];
                i--;
            }
                
            
            if(k)
            {
                carry += (k%10);   
                k /= 10;
            }

            ret.push_back(carry % 10);
            
            carry = carry/10;
        }
        
        if(carry)
            ret.push_back(carry);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};