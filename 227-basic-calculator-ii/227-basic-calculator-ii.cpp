class Solution {
public:    
    int calculate(string s) {
    
        long ret = 0;
        
        char op = '+';
        
        s = s + '+';
        
        stack<int> nums;
        long num = 0;
        for(auto it : s)
        {
            if(isdigit(it))
            {
                num = (long)num*10 + (it - '0');
            }
            else if(it == '+' || it == '-' || it == '*' || it == '/')
            {
                if(op == '+')
                    nums.push(num);
                else if(op == '-')
                     nums.push(-num);
                else if(op == '*')
                {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top*num);
                }
                else if(op == '/')
                {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top/num);
                }
                    
                op = it;
                num = 0;
            }
        }
        
        while(!nums.empty())
        {
            ret += nums.top();
            nums.pop();
        }
        
        return ret;
    }
};