class Solution {
public:
    int targetSum;
    unordered_map<string, bool> memo;
    bool dfs(vector<int>& nums, int k, int cur_i, string& visited, int target)
    {
        if(k == 1)
            return true;

        if(memo.find(visited) != memo.end())
            return memo[visited];
        
        if(target == 0)
            return memo[visited] = dfs(nums, k-1, 0, visited, targetSum);

        for(int i=cur_i;i< nums.size();i++)
        {
            if(target - nums[i] < 0)
                continue;
            
            if(visited[i] == '0')
            {
                visited[i] = '1';
                if(dfs(nums, k, i+1, visited, target - nums[i]))
                    return true;
                visited[i] = '0';
            }
        }
        
        return memo[visited] = false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(totalSum % k != 0)
            return false;
        
        targetSum = totalSum/k;
        
        sort(nums.begin(), nums.end(), greater<>());
        
        string visited(n, '0');
        
        return dfs(nums, k, 0, visited, targetSum);
    }
};