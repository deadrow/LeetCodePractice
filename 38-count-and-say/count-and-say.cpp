class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        string cur = countAndSay(n-1);
        int freq=0;
        char prev;
        string ret;
        for(int i=0;i<cur.size();i++){
            if(i==0 or cur[i]==cur[i-1]){
                freq++;
            }
            else {
                ret += to_string(freq) + prev;
                freq = 1;
            }
            prev = cur[i];
        }

        if(freq) ret += to_string(freq) + prev;
        return ret;
    }
};