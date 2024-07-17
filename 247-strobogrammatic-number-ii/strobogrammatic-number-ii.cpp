class Solution {
public:
    unordered_map<char, char>dict{{'0','0'},{'1','1'}, {'6','9'}, {'8','8'}, {'9', '6'}};
    vector<string>ret;
    void backtrack(int n, int i, string cur){
        if(i>= (n+1)/2){
            ret.push_back(cur);
            return;
        }
        for(auto it : dict){
            if(i==0 and it.first=='0') continue;
            if(i==n-i-1 and (it.first=='6' or it.first=='9')) continue;
            cur[i]=it.first;
            cur[n-i-1]=it.second;
            backtrack(n, i+1, cur);
        }
    }
    vector<string> findStrobogrammatic1(int n) {
        if(n==1) ret.push_back("0");
        string cur(n, ' ');
        backtrack(n, 0, cur);
        return ret;
    }

    vector<string> backtrack(int n, int final){
        if(n == 0) return {""};
        if(n == 1) return {"0","1","8"};

        vector<string> words = backtrack(n-2, final);
        vector<string> ret;
        for(auto word : words){
            for(auto it : dict){
                if(it.first != '0' or final != n) 
                    ret.push_back(it.first + word + it.second);
            } 
        }
        return ret;
    }
    vector<string> findStrobogrammatic(int n) {
        return backtrack(n, n);
    }
};