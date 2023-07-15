class Solution {
public:
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
        int n = events.size();
        // memo.resize(n+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        sort(events.begin(), events.end());
        return dp(events, k, 0, -1);
    }
};