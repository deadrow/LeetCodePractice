class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int num =0;
        char op='+';
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0');
            }
            if((!isdigit(s[i]) and !isspace(s[i])) or i == s.size()-1){
                if(op == '+'){
                    st.push(num);
                } else if(op == '-'){
                    st.push(-num);  
                } else if(op == '*'){
                    int num1 = st.top();
                    st.pop();
                    st.push(num1*num);
                } else if(op == '/'){
                    int num1 = st.top();
                    st.pop();
                    st.push(num1/num);
                }
                op = s[i];
                num = 0;
            }
        }

        int ret=0;
        while(!st.empty()){
            ret += st.top();
            st.pop();
        }
        return ret;
    }
};