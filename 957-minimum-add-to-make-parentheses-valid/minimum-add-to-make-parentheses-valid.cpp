class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                if(st.empty())
                    count++;
                else
                    st.pop();
            }
        }
        return count + st.size();
    }
};