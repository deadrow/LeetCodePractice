class Solution {
public:
    vector<string> valid{"01", "10", "11"};
    vector<string> backtrack(int n){
        if(n == 1) return {"0", "1"};
        if(n == 2) return {"01", "10", "11"};
        vector<string> ret = backtrack(n-1);
        vector<string> newRet;
        for(auto it : ret){
            if(it.back() != '0')
                newRet.push_back(it + "0");
            newRet.push_back(it + "1");
        }
        return newRet;
    }
    vector<string> validStrings(int n) {
        return backtrack(n);
    }
};