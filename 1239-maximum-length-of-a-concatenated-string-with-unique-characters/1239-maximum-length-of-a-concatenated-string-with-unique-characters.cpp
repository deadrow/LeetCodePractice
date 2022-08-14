class Solution {
public:
    int dfs(vector<string>& arr, int mask, int cur_i)
    {
        if(cur_i >= arr.size())
            return 0;
        
        int take = 0;
        bool unique = true;
        int curMask = mask;
        for(auto it : arr[cur_i])
        {
            int i = it-'a';
            if((curMask >> i) & 1)
            {
                unique = false;
                break;
            }
            
            curMask = (curMask | (1 << i));
        }
        
        if(unique)
        {
            take = (int)arr[cur_i].size() + dfs(arr, curMask, cur_i+1);
        }
            
        int leave = dfs(arr, mask, cur_i+1);
        return max(take, leave);
    }
    
    int maxLength(vector<string>& arr) {
        int mask = 0;
        return dfs(arr, mask, 0);
    }
};