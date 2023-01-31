class Solution {
public:
    vector<pair<int,int>>ageScorePair;
    vector<int>memo;
    int dp(int cur_i, int prev, int n)
    {
        if(cur_i >= n)
            return 0;
        
        if(memo[prev+1] != -1)
            return memo[prev+1];
        int take = 0;
        if(prev == -1 || ageScorePair[cur_i].second >= ageScorePair[prev].second)
            take = ageScorePair[cur_i].second + dp(cur_i+1, cur_i, n);
            
        int leave = dp(cur_i+1, prev, n);
        return memo[prev+1] = max(take, leave);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        for(int i=0;i<n;i++)
            ageScorePair.push_back({ages[i], scores[i]});
        
        sort(ageScorePair.begin(), ageScorePair.end());
        memo.resize(n, -1);
        return dp(0, -1, n);
    }
};