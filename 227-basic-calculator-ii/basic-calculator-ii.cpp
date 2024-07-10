class Solution {
public:
    int calculate1(string s) {
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
    
    int calculate(string s) {
        int prev=0;
        int num=0;
        char op='+';
        int ret=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0');
            }
            if((!isdigit(s[i]) and !isspace(s[i])) or i == s.size()-1){
                if(op == '+'){
                    ret += prev;
                    prev = num;
                } else if(op == '-'){
                    ret += prev;
                    prev = -num;  
                } else if(op == '*'){
                    prev = prev*num;
                } else if(op == '/'){
                    prev = prev/num;
                }
                op = s[i];
                num = 0;
            }
        }

        return ret + prev;
    }
};