class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int>& nums, vector<int>&cur, int cur_i)
    {
        if(cur.size() > 1)
            res.push_back(cur);
                
        set<int> curNums;
        for(int i=cur_i;i<nums.size();i++)
        {
            if(curNums.find(nums[i]) != curNums.end())
                continue;
            
            if(cur.empty() || nums[i] >= cur.back())
            {
                curNums.insert(nums[i]);
                cur.push_back(nums[i]);
                backtrack(nums, cur, i+1);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences1(vector<int>& nums) {
        vector<int>cur;
        backtrack(nums, cur, 0);
        return res;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // bitmasking solution
        // basically we can represent vector of n size
        // 2^n numbers
        
        int n = nums.size();
        set<vector<int>> unique;
        
        for(int i=0;i<(1<<n);i++)
        {
            vector<int>sequence;
            for(int j=0;j<n;j++)
            {
                if(i & (1 << j))
                    sequence.push_back(nums[j]);
            }
            
            if(sequence.size() > 1)
            {
                bool increasing = true;
            
                for(int k=1;k<sequence.size();k++)
                {
                    if(sequence[k] < sequence[k-1])
                    {
                        increasing = false;
                        break;
                    }
                }

                if(increasing)
                    unique.insert(sequence);
            }

        }
        
        return vector(unique.begin(), unique.end());
    }
};