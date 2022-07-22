class Solution {
public:
    string reverseWords(string s) {
        
        int start_i = -1;
        int end_i = -1;
        
        stack<string>st;
        
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                if(start_i == -1)
                    start_i = i;
            }
            else if(isspace(s[i]))
            {
                if(start_i != -1)
                {
                    st.push(s.substr(start_i, i-start_i));
                    start_i = -1;
                }
            }
        }
        
        if(start_i < s.length())
            st.push(s.substr(start_i));
        
        string res;
        while(!st.empty())
        {
            res += st.top();
            
            if(st.size() > 1)
                res += " ";
            st.pop();
        }
        
        return res;
    }
};