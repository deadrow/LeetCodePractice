class Solution {
public:
    
    int shortestWay(string source, string target) {
        int m = source.size();
        int n = target.size();
        
        unordered_map<char, bool> cache;
        for(auto it : source)
            cache[it] = true;
        
        int count = 0;
        int i=0;
        int j=0;
        
        int ans = 0;
        while(j < n)
        {
            if(!cache[target[j]])
                return -1;
            
            while(i < m)
            {
                if(source[i] == target[j])
                {
                    i++;
                    j++;
                }
                else
                    i++;
            }
            
            ans += 1;
            i= 0;
        }
        
        return ans;
    }
};