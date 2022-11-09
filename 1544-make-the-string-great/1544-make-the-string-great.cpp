class Solution {
public:
    string makeGood(string s) {
        if(s.empty())
            return s;
        
        vector<char> st;

        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && (st.back() == (s[i]+32) || st.back() == (s[i]-32)))
                st.pop_back();
            else
                st.push_back(s[i]);
        }
        
        string ret(st.begin(), st.end());
        return ret;
    }
};