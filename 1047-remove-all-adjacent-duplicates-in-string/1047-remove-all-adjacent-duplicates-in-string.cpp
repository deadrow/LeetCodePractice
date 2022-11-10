class Solution {
public:
    string removeDuplicates(string s) {
        if(s.empty())
            return s;
        
        vector<char> st;

        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && st.back() == s[i])
                st.pop_back();
            else
                st.push_back(s[i]);
        }
        
        string ret(st.begin(), st.end());
        return ret;
    }
};