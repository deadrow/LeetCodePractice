class Solution {
public:
    vector<vector<int>>memo;
    bool backtrack(string& s, int open, int i){
        if(i >= s.size()){
            return open == 0;
        }

        if(memo[i][open]!= -1) return memo[i][open];

        bool isValid = false;
        if(s[i] == '*'){
            isValid |= backtrack(s, open+1, i+1);
            if(open)
                isValid |= backtrack(s, open-1, i+1);
            isValid |= backtrack(s, open, i+1);
        }
        else if(s[i] == '(')
            isValid |= backtrack(s, open+1, i+1);
        else if(s[i] == ')'){
            if(open)
                isValid |= backtrack(s, open-1, i+1);
        }
            
        return memo[i][open]=isValid;
    }
    bool checkValidString(string s) {
        memo.resize(s.size(),vector<int>(s.size(),-1));
        return backtrack(s, 0, 0);
    }
};