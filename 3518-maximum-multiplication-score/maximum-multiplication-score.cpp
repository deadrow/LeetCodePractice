class Solution {
public:
    vector<vector<long long>>memo;
    long long dp(vector<int>& a, vector<int>& b, int i, int j){
        if(j>=b.size() and i< a.size()) return INT_MIN;
        if(i>=a.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        long long take = INT_MIN;
        long long ret = dp(a, b, i+1, j+1);
        if(ret != INT_MIN)
            take = (long long)b[j]*a[i] + ret;
        long long leave = dp(a, b, i, j+1);
        return memo[i][j]=max(take, leave);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        memo.resize(a.size(), vector<long long>(b.size(), -1));
        return dp(a, b, 0, 0);
    }
};