class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int len1 = num1.size()-1;
        int len2 = num2.size()-1;
        int carry = 0;
        // 11  and 321
        while(len1 >= 0 || len2 >= 0) {
            int n1 = len1 >=0 ? num1[len1]-'0' : 0;
            int n2 = len2 >=0 ? num2[len2]-'0' : 0;
            ret += ((n1 + n2 + carry) % 10 + '0');
            carry = (n1 + n2 + carry)/10;
            len1--;len2--;
        }

        if(carry)
            ret += '1';

        reverse(ret.begin(), ret.end());
        return ret;
    }
};