class Solution {
public:
    vector<string>res;

    void backtrack(string& s, string cur, int cur_i, int dots)
    {
        if(dots > 3)
        {
            if(cur_i == s.size()) // we reached end of string
                res.push_back(cur);
            return; // return in other cases
        }

        for(int steps=1;steps<=3;steps++)
        {
            if(cur_i + steps <= s.size())
            {
                string sub = s.substr(cur_i, steps);
                if(sub.size() > 1 && ((sub[0] == '0') || (stoi(sub) > 255)))
                    continue;

                backtrack(s, cur + sub + ((dots == 3) ? "" : "."), cur_i+steps, dots+1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        
        if(s.size() < 4)
            return res;
        
        string cur;
        backtrack(s, cur, 0, 0);
        return res;
    }
};