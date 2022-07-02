class Solution {
public:
    int m, n;
    int dp(string source, string target, int i, int j)
    {
        if(i == m || j == n)
            return 0;
        
        if(source[i] == target[j])
            return 1 + dp(source, target, i+1, j+1);
        
        return dp(source, target, i+1, j);
    }
    
    int shortestWay(string source, string target) {
        this->m = source.size();
        this->n = target.size();
        
        int count = 0;
        while (!target.empty()) {
            int match = dp(source, target, 0, 0);
            if(match == 0)
                return -1;
            
            count++;
            target = target.substr(match);
        }
        
        return count;
    }
};