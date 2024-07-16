class Solution {
public:
    int minInsertions(string s) {
        stack<int>st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') {
                if(i+1 < s.size() and s[i+1] == ')') {
                    if(st.empty()) count++;
                    else st.pop();
                    i++;
                } else {
                    // single )
                    if(st.empty()) count += 2;
                    else {
                        count += 1;
                        st.pop();
                    }
                }
            }
        }
        return count + st.size()*2;
    }
};