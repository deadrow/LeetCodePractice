class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        
        int sign = 1;
        int curNum = 0;
        int res = 0;
        
        for(auto i : s)
        {
            if(isdigit(i))
            {
                curNum = curNum*10 + (i-'0');
            }
            else 
            {
                if(i == '+')
                {
                    res += sign*curNum;
                    sign = 1;
                    curNum = 0;
                }
                else if(i == '-')
                {
                    res += sign*curNum;
                    sign = -1;
                    curNum = 0;
                }
                else if(i == '(')
                {
                    st.push(res);
                    st.push(sign);
                    sign = 1;
                    res = 0;
                }
                else if(i == ')')
                {
                    res += sign*curNum;
                    res *= st.top();
                    st.pop();
                    res += st.top();
                    st.pop();
                    curNum = 0;
                }
            }
        }
        
        if(curNum != 0)
            res += sign*curNum;
        return res;
    }
};