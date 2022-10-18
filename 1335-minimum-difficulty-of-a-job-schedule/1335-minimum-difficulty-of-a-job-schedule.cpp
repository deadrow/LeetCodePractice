class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<int>& jobDifficulty, int i, int d)
    {
        if(d < 0)
            return 300001;
        
        if(i == jobDifficulty.size())
        {
            if(d == 0)
                return 0;
            return 300001;
        }
        
        if(memo[i][d] != -1)
            return memo[i][d];

        int maxJob = INT_MIN;
        int minDiff = INT_MAX;
        for(int k=i;k<jobDifficulty.size();k++)
        {
            maxJob = max(maxJob, jobDifficulty[k]);
            minDiff = min(minDiff, maxJob + dp(jobDifficulty, k+1, d-1));
        }
        
        return memo[i][d] = minDiff;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d)
            return -1;
        
        memo.resize(jobDifficulty.size()+1, vector<int>(d+1, -1));
        return dp(jobDifficulty, 0, d);
    }
};