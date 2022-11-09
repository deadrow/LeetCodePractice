class Solution {
public:
    string makeGood(string s) {
        if(s.empty())
            return s;
        
        stack<char> st;
        
        st.push(s[0]);
        
        for(int i=1;i<s.size();i++)
        {
            if(!st.empty() && (st.top() == (s[i]+32) || st.top() == (s[i]-32)))
                st.pop();
            else
                st.push(s[i]);
        }
        
        string ret;
        while(!st.empty())
        {
            ret = st.top() + ret;
            st.pop();
        }
            
        
        return ret;
    }
};