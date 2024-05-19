class Solution {
public:
    vector<string>ret;
    void generate(int n, int leftCount, int rightCount, string s) {
        if(s.size() == 2*n) {
            ret.push_back(s);
            return;
        }

        if(leftCount < n) {
            s.push_back('(');
            generate(n, leftCount+1, rightCount, s);
            s.pop_back();
        }
        if(leftCount > rightCount) {
            s.push_back(')');
            generate(n, leftCount, rightCount+1, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        generate(n, 0, 0, s);
        return ret;
    }
};