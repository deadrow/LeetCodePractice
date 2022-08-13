class Solution {
public:
    int maxLen = 0;
    int count[26] = {0};
    void dfs(vector<string>& arr, string cur, int cur_i)
    {
        if(cur_i >= arr.size())
            return;
        
        for(int i=cur_i;i<arr.size();i++)
        {
            bool present = false;
            for(auto it : arr[i])
            {
                if(count[it-'a'] > 0)
                {
                    present = true;
                }

                count[it-'a']++;
            }
            
            if(!present)
            {
                int wordSize = arr[i].size();
                cur += arr[i];
                maxLen = max(maxLen, (int)cur.size());
                dfs(arr, cur, i+1);
                
                // backtrack
                cur.erase(cur.size()-wordSize);
                
                for(auto it : arr[i])
                {
                    count[it-'a']--;
                }
            }
            else
            {
                for(auto it : arr[i])
                {
                    count[it-'a']--;
                }
                
                dfs(arr, cur, i+1);
            }
        }
    }
    
    int maxLength(vector<string>& arr) {
        string cur;
        dfs(arr, cur, 0);
        return maxLen;
    }
};