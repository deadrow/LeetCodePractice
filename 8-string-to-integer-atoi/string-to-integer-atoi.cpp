class Solution {
public:

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        bool negative = false;
        // remove space
        while(i < n and s[i] == ' ') i++;

        if(i< n) {
            if(s[i] == '-') {
                negative = true;
                i++;
            }
            else if(s[i] == '+') {
                negative = false;
                i++;
            }
        }

        int res=0;
        while(i<n and isdigit(s[i])) {
            int digit = s[i]-'0';
            if(res > INT_MAX/10 or (res == INT_MAX/10 and digit>7)) return negative ? INT_MIN:INT_MAX;
            res = res*10+digit;
            i++;
        }
        return negative ? res*-1:res;
    }
};