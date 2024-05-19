class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>st;
        string ret;
        for(auto it : s) {
            if(it != '(' and it != ')') ret += it;
            else {
                if(it == '(') {
                    ret += it;
                    st.push(it);
                } else {
                    if(!st.empty()) {
                        ret += it;
                        st.pop();
                    }
                }
            }
        }

        int leftCount = st.size();
        cout << leftCount;
        if(leftCount > 0) {
            st = stack<char>();
            for(int i=ret.size()-1;i>=0;i--) {
                if(ret[i] == '(' && leftCount-- > 0)
                    continue;
                else
                    st.push(ret[i]);
            }
            ret.clear();
        }

        while(!st.empty()) {
            ret += st.top();
            st.pop();
        }
        return ret;
    }
};