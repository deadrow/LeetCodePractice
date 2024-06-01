class Solution {
public:
    int reverse(int x) {
        string ret = to_string(x);
        bool negative = ret[0] == '-'? true:false;
        ::reverse(ret.begin(),ret.end());
        long retNum = stol(ret.substr(0,ret.size()));
        if(retNum < INT_MIN or retNum > INT_MAX) return 0;
        return negative ? retNum*-1 : retNum;
    }
};