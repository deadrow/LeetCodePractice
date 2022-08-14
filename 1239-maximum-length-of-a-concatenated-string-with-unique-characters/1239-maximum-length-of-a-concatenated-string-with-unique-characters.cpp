class Solution {
public:
    int dfs(vector<string>& arr, int mask, int cur_i)
    {
        if(cur_i >= arr.size())
            return 0;
        
        int take = 0;
        bool unique = true;
        int newMask = mask;
        for(auto it : arr[cur_i])
        {
            int i = it-'a';
            if((newMask >> i) & 1)
            {
                unique = false;
                break;
            }
            
            newMask = (newMask | (1 << i));
        }
        
        if(unique)
        {
            take = (int)arr[cur_i].size() + dfs(arr, newMask, cur_i+1);
        }
            
        int leave = dfs(arr, mask, cur_i+1);
        return max(take, leave);
    }
    
    int maxLength(vector<string>& arr) {
        int mask = 0;
        return dfs(arr, mask, 0);
    }
};