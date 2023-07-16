class Solution {
public:

#if 0 // self
    unordered_map<string, int>memo;
    int dp(vector<vector<int>>& events, int k, int cur_i, int prev_i)
    {
        string hash = to_string(cur_i) + "#" + to_string(prev_i) + "# " + to_string(k);
        if(cur_i >= events.size() || k == 0)
            return 0;
        
        if(memo.count(hash))
            return memo[hash];

        int leave = dp(events, k, cur_i+1, prev_i);
        int take = 0;
        if(prev_i == -1 || (events[cur_i][0] > events[prev_i][1]))
            take = events[cur_i][2] + dp(events, k-1, cur_i+1, cur_i);

        return memo[hash] = max(take, leave);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        return dp(events, k, 0, -1);
    }

#else
    vector<vector<int>>memo;
    int dp(vector<vector<int>>& events, int k, int cur_i)
    {
        if(cur_i >= events.size() || k == 0)
            return 0;
        
        if(memo[cur_i][k] != -1)
            return memo[cur_i][k];

        int leave = dp(events, k, cur_i+1);
        
        int nextIdx = upper_bound(events.begin(), events.end(), events[cur_i][1], 
            [=](int t, const auto& a) {
                return a[0] > t;
            }) - events.begin();

        int take = events[cur_i][2] + dp(events, k-1, nextIdx);

        return memo[cur_i][k] = max(take, leave);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        memo.resize(events.size(), vector<int>(k+1, -1));
        sort(events.begin(), events.end());
        return dp(events, k, 0);
    }
#endif
};