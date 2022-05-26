class Solution {
public:
    vector<int> nums;
    vector<char>ops;
    
    void seperateNumsAndOps(string& s)
    {
        int lastOpPos = -1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                string exp = s.substr(lastOpPos+1, i);
                nums.push_back(stoi(exp));
                ops.push_back(s[i]);
                lastOpPos = i;
            }
        }
        
        nums.push_back(stoi(s.substr(lastOpPos+1)));
    }
    
    vector<int> solve(string& s, int i, int j)
    {
        if(i == j)
            return {nums[i]};
        
        vector<int> left, right, ans;
        for(int k=i;k<j;k++)
        {
            vector<int> left =  solve(s, i, k);
            vector<int> right = solve(s, k+1, j);
            
            for(auto it : left)
            {
                for(auto it1 : right)
                {
                    if(ops[k] == '+')
                       ans.push_back(it+it1);
                    else if(ops[k] == '-')
                        ans.push_back(it-it1);
                    else if(ops[k] == '*')
                        ans.push_back(it*it1);
                }
            }
        }
        
        return ans;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        seperateNumsAndOps(expression);
        return solve(expression, 0, nums.size()-1);
    }
};