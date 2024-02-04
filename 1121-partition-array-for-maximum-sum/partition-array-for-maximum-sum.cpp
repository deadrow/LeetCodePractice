class Solution {
public:
    vector<int>memo;
    int dp(vector<int>& arr, int k, int cur_i)
    {
        if(cur_i >= arr.size())
            return 0;

        if(memo[cur_i] != -1)
            return memo[cur_i];

        int lim = min(cur_i+k, (int)arr.size());
        int curMax = 0;
        int maxSum = 0;
        for(int i=cur_i;i<lim;i++)
        {
            curMax = max(curMax, arr[i]);
            maxSum = max(maxSum, (i-cur_i+1)*curMax + dp(arr, k, i+1));
        }

        return memo[cur_i]= maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memo.resize(arr.size(), -1);
        return dp(arr, k, 0);
    }
};