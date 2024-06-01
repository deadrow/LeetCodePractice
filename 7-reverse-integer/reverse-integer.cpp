class Solution {
public:
    int reverse1(int x) {
        // when it allows storing in 64 bit numbers
        string ret = to_string(x);
        bool negative = ret[0] == '-'? true:false;
        ::reverse(ret.begin(),ret.end());
        long retNum = stol(ret.substr(0,ret.size()));
        if(retNum < INT_MIN or retNum > INT_MAX) return 0;
        return negative ? retNum*-1 : retNum;
    }

    int reverse(int x) {
        int ret = 0;
        while(x) {
            if(ret > INT_MAX/10 or ret< INT_MIN/10) return 0;
            ret = ret*10 + x%10;
            x /= 10;
        }
        return ret;
    }
};