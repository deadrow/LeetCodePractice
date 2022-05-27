class Solution {
public:
    unordered_map<string, bool> memo;
    bool solve(string s1, string s2)
    {
        string key = s1+"#"+s2;
        
        if(s1.compare(s2) == 0)
            return true;
        
        if(s1.size() <=1)
            return false;
        
        if(memo.find(key) != memo.end())
            return memo[key];
        
        bool flag = false;
        int n = s1.size();
        for(int i=1; i <= n-1;i++)
        {
            // check if first half of s1 is scrambled of second half of s2
            // if we swapped
            bool case1 = solve(s1.substr(0,i) , s2.substr(n-i, i)) && solve(s1.substr(i, n-i), s2.substr(0,n-i));
            bool case2 = solve(s1.substr(0,i) , s2.substr(0, i)) && solve(s1.substr(i, n-i), s2.substr(i, n-i));
            
            if(case1 || case2)
            {
                flag = true;
                break;
            }
        }
        
        return memo[key] = flag;
    }
    
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};