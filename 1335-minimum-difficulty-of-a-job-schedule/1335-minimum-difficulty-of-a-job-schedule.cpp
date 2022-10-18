class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<int>& jobDifficulty, int i, int d)
    {
        if(d < 0)
            return INT_MAX;
        
        if(i == jobDifficulty.size())
        {
            // if days are 0 means we finished all jobs o
            if(d == 0)
                return 0;
            return INT_MAX;
        }
        
        if(memo[i][d] != -1)
            return memo[i][d];

        int maxJob = INT_MIN;
        int minDiff = INT_MAX;
        for(int k=i;k<jobDifficulty.size();k++)
        {
            maxJob = max(maxJob, jobDifficulty[k]);
            int temp = dp(jobDifficulty, k+1, d-1);
            if(temp!= INT_MAX)
                minDiff = min(minDiff, maxJob + temp);
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