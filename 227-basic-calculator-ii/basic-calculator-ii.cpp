class Solution {
public:
    int sum(stack<int>&st){
        int sum=0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
    void evaulate(stack<int>&st, char op, int num){
        if(op == '+')
            st.push(num);
        else if(op == '-')
            st.push(-num);
        else if(op=='*'){
            int num1= st.top();
            st.pop();
            st.push(num1*num);
        } else if(op=='/'){
            int num1= st.top();
            st.pop();
            st.push(num1/num);
        }
    }
    pair<int,int> helper(string s){
        long num=0;
        char op='+';
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))
                num = num*10 + s[i]-'0';
            else if(s[i]== '+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
                evaulate(st, op, num);
                op = s[i];
                num = 0;
            }
            // } else if(s[i] == '('){
            //     auto ret = helper(s.substr(i+1));
            //     num += ret.first;
            //     i += ret.second;
            // } else if(s[i] == ')'){
            //     evaulate(st, op, num);
            //     return {sum(st), i+1};
            // }
        }
        evaulate(st, op, num);
        return {sum(st), s.size()};
    }
    int calculate(string s) {
        return helper(s).first;
    }
};