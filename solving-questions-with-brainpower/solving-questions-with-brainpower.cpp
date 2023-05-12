class Solution {
public:
    // classic knapsack with jump
    vector<long>memo;
    long long dp(vector<vector<int>>& questions, int cur_i)
    {
        if(cur_i >= questions.size())
            return 0;

        if(memo[cur_i] != -1)
            return memo[cur_i];

        long take = questions[cur_i][0] + dp(questions, cur_i+questions[cur_i][1]+1);
        long leave = dp(questions, cur_i+1);
        return memo[cur_i] = max(take, leave);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        memo.resize(questions.size(), -1);
        return dp(questions, 0);
    }
};