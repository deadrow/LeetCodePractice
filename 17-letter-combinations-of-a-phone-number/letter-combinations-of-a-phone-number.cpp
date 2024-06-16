class Solution {
public:
    vector<string> res;
    map<char, string>dict;
    void backtrack(string digits, string cur, int cur_i){
        if(cur.size() == digits.size()){
            res.push_back(cur);
            return;
        }
        string letters = dict[digits[cur_i]];
        for(auto it : letters){
            cur.push_back(it);
            backtrack(digits, cur, cur_i+1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        dict['2']= "abc";
        dict['3']="def";
        dict['4']="ghi";
        dict['5']="jkl";
        dict['6']="mno";
        dict['7']="pqrs";
        dict['8']="tuv";
        dict['9']="wxyz";
        string cur;
        backtrack(digits, cur, 0);
        return res;
    }
};