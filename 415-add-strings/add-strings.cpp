class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int len1 = num1.size();
        int len2 = num2.size();
        int i=0, j=0;
        int carry = 0;
        // 11  and 321
        while(i < len1 && j < len2) {
            int num = num1[i]-'0' + num2[j]-'0' + carry;
            ret += (num % 10 + '0');
            carry = num/10;
            i++;j++;
        }

        if(i == len1) {
            while( j < len2) {
                int num = num2[j]-'0' + carry;
                ret += (num % 10 + '0');
                carry = num/10;
                j++;
            }
        } else {
            while( i < len1) {
                int num = num1[i]-'0' + carry;
                ret += (num % 10 + '0');
                carry = num/10;
                i++;
            }
        }

        if(carry)
            ret += '1';

        reverse(ret.begin(), ret.end());
        return ret;
    }
};