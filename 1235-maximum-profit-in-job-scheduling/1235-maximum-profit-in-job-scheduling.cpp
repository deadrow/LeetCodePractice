class Solution {
public:
    // Self TLE for big test cases. Simple knapsack
    vector<vector<int>>memo;
    int dp1(vector<vector<int>>& jobs, int cur_i, int last_i)
    {
        if(cur_i == jobs.size())
            return 0;
        
        if(last_i != -1 && memo[cur_i][last_i] != -1)
            return memo[cur_i][last_i];
        
        int take = 0;
        if(last_i == -1 || jobs[cur_i][0] >= jobs[last_i][1])
        {
            take += jobs[cur_i][2] + dp1(jobs, cur_i+1, cur_i);
        }
        
        int leave = dp1(jobs, cur_i+1, last_i);
        
        if(last_i != -1)
            memo[cur_i][last_i] = max(take, leave);
        
        return max(take, leave);
    }
    
    int jobScheduling1(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        for(int i=0;i<startTime.size();i++)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        memo.resize(jobs.size()+1, vector<int>(jobs.size()+1, -1));
        return dp1(jobs, 0, -1);
    }
    
    vector<int>memo1;
    // With binary search to find the next slot
    int dp(vector<vector<int>>& jobs, vector<int>& startTime, int cur_i)
    {
        if(cur_i == jobs.size())
            return 0;
        
        if(memo1[cur_i] != -1)
            return memo1[cur_i];
        
        int nextIndexToPick = lower_bound(startTime.begin(), startTime.end(), jobs[cur_i][1]) - startTime.begin();
        int take = jobs[cur_i][2] + dp(jobs, startTime, nextIndexToPick);
        
        int leave = dp(jobs, startTime, cur_i+1);
        
        return memo1[cur_i] = max(take, leave);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        for(int i=0;i<startTime.size();i++)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        // assign sorted starttime values again
        for(int i=0;i<jobs.size();i++)
            startTime[i] = jobs[i][0];
        
        memo1.resize(jobs.size()+1, -1);
        return dp(jobs, startTime, 0);
    }
};