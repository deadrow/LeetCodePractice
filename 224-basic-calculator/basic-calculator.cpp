class Solution {
public:
    int sum(stack<int>&st){
        int ret=0;
        while(!st.empty()){
            ret += st.top();
            st.pop();
        }
        return ret;
    }
    void evaluate(stack<int>&st, char op, int num){
        if(op == '+'){
            st.push(num);
        } else if(op == '-'){
            st.push(-num);  
        } else if(op == '('){
            int num1 = st.top();
            st.pop();
            st.push(num1*num);
        } else if(op == '/'){
            int num1 = st.top();
            st.pop();
            st.push(num1/num);
        }
    }
    pair<int,int> helper(string& s){
        int num = 0;
        char op='+';
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0');
            }
            else if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
                evaluate(st, op, num);
                op = s[i];
                num = 0;
            } else if(s[i] == '('){
                string str = s.substr(i+1);
                pair<int,int> curRes = helper(str);
                num = curRes.first;
                i += curRes.second;
            } else if(s[i] == ')'){
                evaluate(st, op, num);
                return {sum(st), i+1};
            }
        }
        evaluate(st, op, num);
        return {sum(st), s.size()};
    }
    int calculate(string s) {
        return helper(s).first;
    }
};