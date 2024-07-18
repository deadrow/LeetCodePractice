class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int i=len1-1,j=len2-1;
        int carry=0;
        string ret;
        while(i>=0 or j>=0){
            int a = i<0 ? 0 : num1[i]-'0';
            int b = j<0 ? 0 : num2[j]-'0';
            ret += (a+b+carry)%10 + '0';
            carry = (a+b+carry)/10;
            i--,j--;
        }

        if(carry) ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};