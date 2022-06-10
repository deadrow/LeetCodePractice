class Solution {
public:
    vector<int>memo;
    int dp(vector<int>& nums, int cur_i, int n, int k)
    {
        if(cur_i == n)
            return nums[cur_i];
        
        if(memo[cur_i] != -1)
            return memo[cur_i];
        
        int ans = INT_MIN;
        int farthest = min(n, cur_i+k);
        for(int pos=cur_i+1;pos<=farthest;pos++)
        {
            int remain = 0;
            if(memo[pos] != -1)
                remain = memo[pos];
            else
                remain = dp(nums, pos, n, k);
            int res = nums[cur_i] + remain;
            ans = max(ans, res);
        }
        
        return memo[cur_i] = ans;
    }
    
    int maxResult(vector<int>& nums, int k) {
        /*
        memo.resize(nums.size(), -1);
        return dp(nums, 0, nums.size()-1, k);
        */
        
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            while(pq.top().second+k < i)
                pq.pop();

            ans = nums[i] + pq.top().first;
            pq.push({ans, i});
        }
        
        return ans;
    }
};