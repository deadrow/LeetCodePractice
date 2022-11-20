class Solution {
public:
    int precedence(char c)
    {
        if(c == '^')
            return 3;
        else if(c == '*' || c == '/')
            return 2;
        else if(c == '+' || c == '-')
            return 1;
        return -1;
    }
    
    int evalRPN(vector<string>& tokens) {
        int res = -1;
        stack<int> nums;
        
        string operations("+-*/");
        for(int i=0;i<tokens.size();i++)
        {
            if(operations.find(tokens[i]) != string::npos)
            {
                int first_num=0;
                int second_num=0;
                if(!nums.empty())
                {
                    first_num = nums.top();
                    nums.pop();
                }
                
                if(!nums.empty())
                {
                    second_num = nums.top();
                    nums.pop();
                }
                
                if(tokens[i] == "+")
                    res = second_num + first_num;
                else if(tokens[i] == "-")
                    res = second_num - first_num;
                else if(tokens[i] == "*")
                    res = second_num * first_num;
                else
                    res = (second_num / first_num);
                
                nums.push(res);
            }
            else
            {
                nums.push(stoi(tokens[i]));
            }
        }
        
        if(res == -1 && !nums.empty())
            res = nums.top();
        
        return res;
    }
    
    vector<string> convertToPostfix(string& s)
    {
        vector<string> ret;
        stack<char> st;
        
        long curNum = -1;
        for(int i=0;i<s.size();i++)
        {
            char cur = s[i];
            if(cur >= '0' && cur <= '9')
            {
                if(curNum == -1)
                    curNum = 0;
                curNum = curNum*10 + cur - '0';
                continue;
            }
                
            if(curNum != -1)
            {
                ret.push_back(to_string(curNum));
                curNum = -1;
            }
                
            if(cur == '(')
                st.push(cur);
            else if(cur == ')')
            {
                while(st.top() != '(')
                {
                    char top = st.top();
                    ret.push_back(string(1, top));
                    st.pop();
                }
                
                st.pop(); // pop '('
            }
            else if(cur == '+' || cur == '-' || cur == '/' || cur == '*')
            {
                // it is operator
                while(!st.empty() && precedence(cur) <= precedence(st.top()))
                {
                    char top = st.top();
                    ret.push_back(string(1, top));
                    st.pop();
                }
                
                st.push(cur);
            }
        }
        
        if(curNum != -1)
            ret.push_back(to_string(curNum));
        
        while(!st.empty())
        {
            ret.push_back(string(1, st.top()));
            st.pop();
        }
        
        return ret;
    }
    
    int calculate(string s) {
        vector<string> postfix = convertToPostfix(s);
        return evalRPN(postfix);
    }
};